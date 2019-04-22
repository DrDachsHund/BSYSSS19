#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
    int status;
    int rc = fork();
	if (rc < 0)
	{
		// fork faild exit
		fprintf(stderr, "fork failed\n");
		exit(1);
		
	} else if (rc == 0)
	{
        //child
        //int a = wait(&status);
        printf("im child pid:%d\n",(int) getpid());
        //printf("a = %d \n",a);
    } else
    {
        //parent
        int a = wait(&status);
        printf("im parent pid:%d\n",(int) getpid());
        printf("a = %d \n",a);
    }  

    return 0;

} 