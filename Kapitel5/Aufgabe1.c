#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	printf("Hello World (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		//fork faild
		fprintf(stderr, "fork faild");
		exit(1);
	} else if (rc == 0) {
		//child process
		printf("Hello, Im the Child (pid:%d)\n", (int) getpid());
	} else {
		//parent process
		printf("Hallo, Im the Parent of %d (pid:%d)\n", rc, (int) getpid());
	}

	printf("Programm Ende!!!");

	return 0;
}
