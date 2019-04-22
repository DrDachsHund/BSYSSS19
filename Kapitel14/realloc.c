#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *array = (int *) malloc(10 * sizeof(int));
    int sizeOfArray = 10;
    int size = 0;

    int input;
    int r;
    printf("Bitte gebe NUR Ganzzahlige Zahlen ein: ");
    int test;
    while ((test = scanf("%d",&input) != EOF) != 0)
    { 
        if (size < sizeOfArray)
        {
            array[size] = input; 
            size++;
        } else
        {
            sizeOfArray += 10;
            array = (int *) realloc(array, sizeOfArray * sizeof(int));
            array[size] = input;
        } 
        //break;
    } 
    //printf("Test = %d %n",test);
    //printf("input = %d %n",input);

    for(int i = 0; i < sizeOfArray; i++)
    {
        printf("array[%d] = %d\n",i,array[i]);
    } 

    free(array);
    return 0;
} 