#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{

    int rc = fork();
	if (rc < 0)
	{
		// fork faild exit
		fprintf(stderr, "fork failed\n");
		exit(1);
		
	} else if (rc == 0)
	{
        //child
        close(STDOUT_FILENO);
        printf("im child pid:%d\n",(int) getpid());
    } else
    {
        //parent
        printf("im parent pid:%d\n",(int) getpid());
    }  

    return 0;

} 