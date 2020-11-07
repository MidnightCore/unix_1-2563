#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//time
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <iostream>
#include <queue>
sem_t x, y;
int main()
{
    int a = 0;
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    int *t = (int *)shmat(shmid, (void *)0, 0);
    //    x = (int*) shmat(shmid,(void*)0,0);
    //    y = (int*) shmat(shmid,(void*)0,0);
    // write logic
    //    sem_wait(&y);
    //    printf("1234567890\n");
    //    sleep(5);
    //    sem_post(&y);
    int num = 0;
    while (true)
    {
        printf("Queue [%d] = %d\n", num + 1, t[num]);
        num++;
        sleep(5);
    }

    shmdt((void *)t);
    //    shmdt((void *)time);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
