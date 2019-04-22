#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{

    int x = 0;
    int fd[2];
    if (pipe(fd) == -1)
    {
    	    fprintf(stderr, "Pipe Faild");
    }

    int status;
    int rc = fork();
    if (rc < 0)
    {
	    // fork faild exit
	    // fprintf(stderr, "fork failed\n");

    	    exit(1);

    } else if (rc == 0)
    {
    	    //child
	    x = 1;
	    close(fd[1]);
	    write(fd[0],&x,sizeof(x));
	    printf("im child \n");
   
    } else
    {
        //parent
        //wait(&status); anstatt wait eine pipe machen 
	close(fd[0]);
	for (;;)
	{
		x = read(fd[1],&x,sizeof(x));
		printf("x = %d",x);
		if (x == 1) break;
		printf("Warte auf child!");
	}
        printf("im parent \n");
    }  

    return 0;

} 
