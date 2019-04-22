#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *data = (int *) malloc(100 * sizeof(int));
    data[100] = 0;
    
    /*
    for(int i = 0; i <= 100; i++)
        printf("data[%d] = %d \n",i,data[i]); 
*/
    return 0; 
} 