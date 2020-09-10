#include "readerwriter.h"

//global variables
int count1 = 0, count2 = 0, read_loops = 0, write_loops = 0;
//bool check_reader, check_writer;

//read_lock function
void read_lock(rwlock_t *rw){
    int numreads;
    numreads = rw->readers + 1;
    printf("Currently reading here: %d\n", numreads);
    for(int i = 0; i < READER_SIZE; i++){
        count1 = i * i;
    }
    printf("Readers finished here: %d\n", numreads);
}

//write_lock function
void write_lock(rwlock_t *rw){
	int numwrites;
    numwrites = rw->writers + 1;

    //printf("Currently writing here: %d\n", numwrites);
	printf("Currently writing here\n");
    for(int j = 0; j < WRITER_SIZE; j++){
        count2 = j * j;
    }
    //printf("Finished writing process: %d\n", numwrites);
	printf("Writers finished here\n");
}

//reader function
void reader(void *arg){
    rwlock_t *rwlock = (rwlock_t *) arg;
 	rwlock_acquire_readlock(rwlock);
	 //check to see if reader has acquired a read lock
	 
	read_lock(rwlock);
	rwlock_release_readlock(rwlock);
}

//writer function
void writer(void *arg){
    rwlock_t *rwlock = (rwlock_t *) arg;
	rwlock_acquire_writelock(rwlock);
	write_lock(rwlock);
	rwlock_release_writelock(rwlock);
}
//end

//textbook functions
void rwlock_init(rwlock_t *rw){
	//initialize writer
	rw->readers = 0;

	//initialize writer
	rw->writers = 0;
	sem_init(&rw->lock, 0, 1); 
	sem_init(&rw->writelock, 0, 1); 
}

void rwlock_acquire_readlock(rwlock_t *rw){
	printf("rwlock acquired here\n");
	sem_wait(&rw->lock);
	rw->readers++;
	if(rw->readers == 1)
		printf("Starving writer here\n");
	    	sem_wait(&rw->writelock);
	sem_post(&rw->lock);
}

void rwlock_release_readlock(rwlock_t *rw){
	printf("rwlock released here\n");
	sem_wait(&rw->lock);
	rw->readers--;
	if(rw->readers == 0)
        	printf("NOT starving writer here\n");
	    	sem_post(&rw->writelock);
	sem_post(&rw->lock);
}

void rwlock_acquire_writelock(rwlock_t *rw){
	sem_wait(&rw->writelock);
}

void rwlock_release_writelock(rwlock_t *rw){
	sem_post(&rw->writelock);
}

//end file
