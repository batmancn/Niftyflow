/*
 *=======================================================================
 *    Filename:mutex.h
 *
 *     Version: 1.0
 *  Created on: March 18, 2018
 *
 *      Author: corvo
 *=======================================================================
 */

#ifndef LOCK_H_8QXT2CMA
#define LOCK_H_8QXT2CMA

#include<pthread.h>

class Lock
{
public:
    explicit Lock(pthread_mutex_t *mx) : mutex(mx)
    {
        int err = pthread_mutex_lock(mutex);
//        printf("[L]: get lock %d\n", err);
    }
    ~Lock()
    {
//        printf("[L]: release lock\n");
        int err = pthread_mutex_unlock(mutex);
        mutex = nullptr;
    }

private:
    Lock(const Lock &l);
    pthread_mutex_t *mutex;
};

#endif /* end of include guard: LOCK_H_8QXT2CMA */
