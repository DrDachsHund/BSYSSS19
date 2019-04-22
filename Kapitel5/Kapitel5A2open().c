#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main (int argc, char* argv[])
{
	int file = open("txt.txt", O_WRONLY | O_TRUNC);
	if (file < 0)
	{
		return 1;
	}		
	printf("hello world (pid:%d)\n", (int) getpid());
	
	int rc = fork();
	if (rc < 0)
	{
		// fork faild exit
		fprintf(stderr, "fork failed\n");
		exit(1);
		
	} else if (rc == 0)
	{
		//child (new process)
		write(file,"hello i am a child \n", 20);
		printf("hallo, i am child (pid:%d)\n", (int) getpid());
		
	} else 
	{
		//parent goes down this path (original process)
		write(file,"hello i am a parent \n",21);
		printf("hallo, i am parent of %d (pid:%d)\n",rc, (int) getpid());
	}

	write(file,"Ende des Programms \n",20);

    close(file);

	return 0;
}