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
        printf("im child \n");
    } else
    {
        //parent
        wait(&status);
        printf("im parent \n");
    }  

    return 0;

} 