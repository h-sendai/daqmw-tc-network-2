#include <sys/syscall.h>

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

void *reader(void *arg);
void *writer(void *arg);

int main(int argc, char *argv[])
{
    int s;
    pthread_t reader_id;
    pthread_t writer_id;

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
    pid_t pid = getpid();
    pid_t tid = syscall(SYS_gettid);

    fprintf(stderr, "writer: pid: %d tid: %d\n", pid, tid);

    return NULL;
}

void *reader(void *arg)
{
    pid_t pid = getpid();
    pid_t tid = syscall(SYS_gettid);

    fprintf(stderr, "reader: pid: %d tid: %d\n", pid, tid);

    return NULL;
}
