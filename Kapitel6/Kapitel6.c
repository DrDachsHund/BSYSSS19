#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const*argv[])
{
	int counter = 100000;
	double start,stop;
	struct timeval time;
	int p;
	
	gettimeofday(&time,NULL);
	start = time.tv_sec + time.tv_usec;
	
	for (int i = 0; i <= counter; i++) {
		p = (int) getpid();
	}
	
	gettimeofday(&time,NULL);
	stop = time.tv_sec + time.tv_usec;
	
	printf("\n Systemcalltime: %.5f \n", ((start -stop) - counter);
	return 0;
	
}

