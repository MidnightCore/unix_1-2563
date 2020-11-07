#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	int a = 0;
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *t = (char *)shmat(shmid, (void *)0, 0);

	printf("data read from memory: %s \n", t);

	shmdt((void *)t);

	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}
