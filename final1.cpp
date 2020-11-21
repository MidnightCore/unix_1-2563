#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <thread>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    int *t = (int *)shmat(shmid, (void *)0, 0);

    int N;
    printf("\nInput Num: ");
    scanf("%d", &N);
    // scanf("%d", t);
    int a[N];
    int i;
    printf("\n--------Thread Use--------\n");

#pragma omp parallel
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 10;
        printf("num thread %d : ", omp_get_thread_num());
        printf("%d\n", a[i]);
    }
    printf("\n");

    shmdt((void *)t);
    return 0;
}
