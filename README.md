# Readers-Writers-Concurrency
This project focuses on the problem of readers/writers in programming around the topic of concurrency.

This problem occurs in programming when different threads are created and all attempt to access shared resources simultaneously.
I created a reader-writer lock for this project in order to manage access of all of the total threads. 

This is handled is by using different functions “rwlock_acquire_writelock()” and “rwlock_release_writelock()” to acquire access to a write lock and to release the access to that write lock. 
The project also introduced the concept of semaphores in programming. These are objects with integer values that I implemented into my project using a write_lock function and also by using sem_wait(), sem_post(). These functions make it so that only one writer can acquire a lock at one time. When a writer acquires a lock, it needs to increment a readers variable and keep track of each reader.
