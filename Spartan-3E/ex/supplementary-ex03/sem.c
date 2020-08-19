#include <err.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define handle_error_en(en, msg) \
    do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define MAX_BUF                 10000
#define MAX_LOOP_COUNT       10000000
#define PRINT_INTERVAL_COUNT   100000

int buf[MAX_BUF];
int debug = 0;
sem_t n_stored;
sem_t n_empty;

void *reader(void *arg);
void *writer(void *arg);

int main(int argc, char *argv[])
{
    int s;
    pthread_t reader_id;
    pthread_t writer_id;

    sem_init(&n_stored, 0, 0);
    sem_init(&n_empty,  0, MAX_BUF);

    s = pthread_create(&reader_id, 0, reader, NULL);
    if (s != 0) {
        handle_error_en(s, "pthread_create");
    }
    s = pthread_create(&writer_id, 0, writer, NULL);
    if (s != 0) {
        handle_error_en(s, "pthread_create");
    }

    s = pthread_join(writer_id, 0);
    if (s != 0) {
        handle_error_en(s, "pthread_join for writer");
    }
    s = pthread_join(reader_id, 0);
    if (s != 0) {
        handle_error_en(s, "pthread_join for writer");
    }
    return 0;
}

void *writer(void *arg)
{
    int loop_counter = 0;
    int write_index = 0;

    while (loop_counter < MAX_LOOP_COUNT) {
        sem_wait(&n_empty);
        buf[write_index] = write_index;
        sem_post(&n_stored);
        write_index ++;
        if (write_index >= MAX_BUF) {
            write_index = 0;
        }
        loop_counter ++;
        if ( (loop_counter % PRINT_INTERVAL_COUNT) == 0) {
            fprintf(stderr, "writer: %d\n", loop_counter);
        }
    }

    return NULL;
}

void *reader(void *arg)
{
    int loop_counter = 0;
    int read_index  = 0;

    while (loop_counter < MAX_LOOP_COUNT) {
        sem_wait(&n_stored);
        if (buf[read_index] != read_index) {
            errx(1, "does not match");
        }
        buf[read_index] = -1;
        sem_post(&n_empty);
        read_index ++;
        if (read_index >= MAX_BUF) {
            read_index = 0;
        }
        loop_counter ++;
        if ( (loop_counter % PRINT_INTERVAL_COUNT) == 0) {
            fprintf(stderr, "reader: %d\n", loop_counter);
        }
    }

    return NULL;
}
