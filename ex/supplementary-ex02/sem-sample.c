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

sem_t sem_var;

void *reader(void *arg);
void *writer(void *arg);

int main(int argc, char *argv[])
{
    int s;
    pthread_t reader_id;
    pthread_t writer_id;

    sem_init(&sem_var, 0, 0);

    s = pthread_create(&reader_id, 0, reader, NULL);
    if (s != 0) {
        handle_error_en(s, "pthread_create");
    }
    s = pthread_create(&writer_id, 0, writer, NULL);
    if (s != 0) {
        handle_error_en(s, "pthread_create");
    }

    s = pthread_join(reader_id, 0);
    if (s != 0) {
        handle_error_en(s, "pthread_join for reader");
    }
    s = pthread_join(writer_id, 0);
    if (s != 0) {
        handle_error_en(s, "pthread_join for writer");
    }
    return 0;
}

void *reader(void *arg)
{

    for (int i = 0; i < 5; ++i) {
        sleep(10);
        fprintf(stderr, "reader trying sem_post()\n");
        sem_post(&sem_var);
        fprintf(stderr, "reader sem_post() done\n");
    }

    return NULL;
}

void *writer(void *arg)
{
    for (int i = 0; i < 5; ++i) {
        fprintf(stderr, "writer trying sem_wait()\n");
        sem_wait(&sem_var);
        fprintf(stderr, "writer sem_wait() done\n");
    }

    return NULL;
}
