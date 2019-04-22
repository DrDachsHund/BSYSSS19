#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    int* p = &i;
    p = NULL; 
    int test = *p;

    printf("test: %d ", test);

    return 0;

}
