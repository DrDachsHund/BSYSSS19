#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *i = (int *) malloc(10 * sizeof(int));
    for(int j = 0; j < 10;j ++)
    {
        i[j] = j; 
    } 
    //int *p = &i[3]; 
    //free(p);
    free(&i[3]);
    printf("i[3] = %d\n ",i[3]);
}
