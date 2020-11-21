#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
	int a = 0;
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *t = (char *)shmat(shmid, (void *)0, 0);

	do
	{
		printf("choose 1 : Read data\nchoose 2 : Exit program\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("Data read from memory : %s \n\n", t);
			break;
		case 2:
			printf("Exit program\n");
			break;
		}
	} while (a == 1);

	shmdt((void *)t);

	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}

