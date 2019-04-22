#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
	int x = 0;
	printf("variable x = %d hello world (pid:%d)\n",x, (int) getpid());
	
	int rc = fork();
	if (rc < 0)
	{
		// fork faild exit
		fprintf(stderr, "fork failed\n");
		exit(1);
		
	} else if (rc == 0)
	{
		//child (new process)
		x = x + 100;
		printf("variable x = %d hallo, i am child (pid:%d)\n",x, (int) getpid());
		
	} else 
	{
		//parent goes down this path (original process)
		x = 100;
		printf("variable x = %d hallo, i am parent of %d (pid:%d)\n",x, rc, (int) getpid());
	}

	printf("Variable x = %d after fork()\n",x);

	return 0;
}
