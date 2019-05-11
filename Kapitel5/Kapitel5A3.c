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
	    close(fd[0]);
	    printf("Hello im Child!\n");
	    write(fd[1],&x,sizeof(x));
	    close(fd[1]);
	    printf("Child x = %d\n",x);
   
    } else
    {
        //parent
        //wait(&status); anstatt wait eine pipe machen 
	//pipe wratet bis etwas geschrieben wurde von child!!!! keine schleife notwendig
	close(fd[1]);
	printf("Waiting for child!\n");
	printf("Parent x = %d befor read\n",x);
	read(fd[0],&x,sizeof(x));
	printf("Partent x = %d after read\n",x);
        printf("im parent \n");
	close(fd[0]);
    }  

    return 0;

} 
