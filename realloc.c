// code to understand realloc 

#include<stdio.h>
#include<stdlib.h>

 
int main()
{
    int *data;
    data = NULL;

    data = realloc(data,20);
    if(data != NULL) //if now data space is not zero and has some space allocated
           printf("Done. \n");

    return 0;
}
