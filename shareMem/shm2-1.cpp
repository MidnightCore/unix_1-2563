#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//Time
#include <time.h>
#include <semaphore.h>
#include <iostream>
#include <queue>

#include <pthread.h>
sem_t x, y;
int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    int *t = (int *)shmat(shmid, (void *)0, 0);
    //    x = (int*) shmat(shmid,(void*)0,0);
    //    y = (int*) shmat(shmid,(void*)0,0);

    //printf("going to write into test structure\n");
    //    sem_wait(&x);
    //    sleep(10);
    //    sem_wait(&y);
    //    printf("55555555\n");
    //    sem_post(&x);
    //
    //    sleep(5);
    //
    //    printf("66666\n");
    //    sem_post(&y);
    std::queue<unsigned int> n;
    int num = 0;
    while (true)
    {

        n.push(rand() % 100);
        t[num] = n.front();
        printf("Queue[%d] = %d \n", num + 1, t[num]);
        num++;
        n.pop();
        sleep(5);
    }
    shmdt((void *)t);
    return 0;
}
