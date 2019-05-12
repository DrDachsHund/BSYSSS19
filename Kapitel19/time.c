#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>


int main(int argc, char const*argv[])
{

	if (argc < 3) {
		printf("Übergabe numver of pages und trails wird benötigt!!\n");
		printf("argc: %d\n",argc);
		return 1;
	}

	printf("Programm Start\n");

	const int PAGESIZE = 8;
	int NUMPAGES = atoi(argv[1]); //4
	int TRAILS = atoi(argv[2]); //1000000000

	printf("NUMPAGES: %d\tTRAILS: %d\n",NUMPAGES,TRAILS);

	int jump = PAGESIZE / sizeof(int);
	double startS,startUS,stopS,stopUS,end,endS,endUS;
	struct timeval time;
	int i,j;
	int *a = (int *) malloc(PAGESIZE * NUMPAGES);

	if(gettimeofday(&time,NULL) < 0)
		return 1;

	startS = time.tv_sec;
	startUS = time.tv_usec;

	for (j = 0; j < TRAILS; j++)	{
		for (i = 0; i < NUMPAGES * jump; i+= jump) {
			a[i] += 1;
		}
	}

	if(gettimeofday(&time,NULL) < 0)
		return 1;

	stopS = time.tv_sec;
	stopUS = time.tv_usec;

	//printf("startS: %f\tstartUS: %f\n",startS,startUS);
	//printf("stopS: %f\tstopUS: %f\n",stopS,stopUS);

	endS = stopS - startS;
	endUS = stopUS - startUS;

	if (endUS < 0) {
		endUS += 1000000;
		endS--;
	}

	endUS = endUS / 1000000;

	end = endS +endUS;

	printf("Time: %f\n",end);


	printf("Programm Finished\n");
	return 0;
}


