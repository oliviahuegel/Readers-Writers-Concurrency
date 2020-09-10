#include <stddef.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#ifndef _READERWRITER_H
#define _READERWRITER_H
#define READER_SIZE 100000
#define WRITER_SIZE 100000

typedef struct _rwlock_t {
    sem_t writelock;
    sem_t lock;
    int readers;
    int writers;
}rwlock_t;

rwlock_t mutex;

//created functions
void read_lock(rwlock_t *rw);
void write_lock(rwlock_t *rw);
void reader(void *arg);
void writer(void *arg);

//textbook functions
void rwlock_init(rwlock_t *rw);
void rwlock_acquire_readlock(rwlock_t *rw);
void rwlock_release_readlock(rwlock_t *rw);
void rwlock_acquire_writelock(rwlock_t *rw);
void rwlock_release_writelock(rwlock_t *rw);

#endif
