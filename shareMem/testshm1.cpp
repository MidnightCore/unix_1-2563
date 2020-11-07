#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	char *t = (char *)shmat(shmid, (void *)0, 0);

	printf("\ngoing to write into test structure\n");
	printf("Enter the string : ");
	scanf("%s", t);
	printf("The string is : %s\n", t);

	shmdt((void *)t);

	return 0;
}