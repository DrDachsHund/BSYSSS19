#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
    int status;
    pid_t pid;

    int rc = fork();
	if (rc < 0)
	{
		// fork faild exit
		fprintf(stderr, "fork failed\n");
		exit(1);
		
	} else if (rc == 0)
	{
        //child
        printf("im child pid:%d\n",(int) getpid());
    } else
    {
        //parent
        waitpid(rc,&status,0);
        printf("im parent pid:%d\n",(int) getpid());
    }  

    return 0;

} 