#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char* argv[])
{
	FILE *fp;
    fp = fopen("txt.txt","w");
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
		fprintf(fp, "hello i am a child \n");
		printf("hallo, i am child (pid:%d)\n", (int) getpid());
		
	} else 
	{
		//parent goes down this path (original process)
		fprintf(fp, "hello i am a parent \n");
		printf("hallo, i am parent of %d (pid:%d)\n",rc, (int) getpid());
	}

    fclose(fp);

	return 0;
}