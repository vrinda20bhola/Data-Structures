#include <stdio.h>
#include <stdlib.h>

// I want you to change the increment and n and see at what point you end up with an extra loop
// played around with this 

int main(int argc, char** argv){

    float i;
    float increment = 0.00000001; //changed
    float n = 0.0001; //changed this 
    int count = 1;

    for (i=0.0; i<n; i+=increment) { //running loop
        printf("Loop Number: %d\n", count);
        count++;
    }

    return 0;
}
