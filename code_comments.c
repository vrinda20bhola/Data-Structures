#include <stdio.h>
#include <stdlib.h>


int blah() {  // making a function 
    int * a; // declaring a pointer a
    int i, n, val; // declaring other variables

    n = 3;
    a = malloc(n * sizeof(int)); //allocating memory 

    // enter data
    i = 0; 
    scanf("%d", &val);
    while(val>0){ 
        a[i] = val;
        i = i+1;
        if(i>=n) {
            n = n*2;
            a = realloc(a, n * sizeof(int));
        }
        scanf("%d", &val);
    }
    n = i;
    a = realloc(a, n * sizeof(int)); // changing the memory allocation by realloc

    // printing data
    for(i=0; i<n; i++) { 
        printf("%d ", a[i]);
    }

    printf("\n\nDone!\n");
    
    return 0;
}

struct nodeType { // making a structure 
    int value;
    struct nodeType * next;
};

typedef struct nodeType Node;

int main(int argc, char **argv) { //argument comments 
    int i, val;
    Node * head = NULL;
    Node * temp = NULL;

    i = 0;
    scanf("%d", &val);
    while(val>0){
        temp = malloc(sizeof(Node));
        temp->value = val;
        temp->next = NULL;

        // if this is the first time
        // or else

        i = i+1; // incrementing the value 
        scanf("%d", &val);
    } 
    return 0;
}
// not able to run the code????