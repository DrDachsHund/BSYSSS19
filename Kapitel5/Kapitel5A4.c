#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    char* args[2];
    args[0] = "/bin/ls";
    args[1] = NULL;
    char* file = "/bin/ls";

    int rc = fork();
	if (rc < 0)
	{
		// fork faild exit
		fprintf(stderr, "fork failed\n");
		exit(1);
		
	} else if (rc == 0)
	{
        //child
        //geht -> execv(args[0],args);
        //execl("/bin/ls","ls");
        // noch falsch execle("/bin/ls","ls",0);
        //execlp(File,Argument0,Argument);
        //geht -> execvp(file,args);
        //execvpe(const char* file, char *const arg][v, char*const env[]p);
        printf("im child \n");
    } else
    {
        //parent
        printf("im parent \n");
    }  

    return 0;

}
