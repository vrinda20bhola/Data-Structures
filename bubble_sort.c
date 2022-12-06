#include <stdio.h>
#include <stdlib.h>
#include <time.h> // introductory 

// except bubble sort function, rest of the functions are copied from existing github  

void bubble_sort(int *a, int n){ 
    int sorted; 
    int i;
    int temp;
    int swap; // initialsiing sorted, i, temp, swap to get the number of elements that are sorted

    for(sorted = 0; sorted<n; sorted++){  // sorted would be from 0 till n-1 to traverse all the elements in the array 
        
        swap = 0;
        for(i=0; i<n-1-sorted; i++){
            if(a[i]>a[i+1]){ // if greater then swap 
                
                // swapping elements 
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                
                swap = 1;
            }
        }   
        if (swap == 0) 
            break; 
    }  
}


//function to print the array with a pointer
// print function is used in kSmallestAmoungUntouched so it is defined before

void printArray(int * a, int size) {
	printf("Array:  ");
	for(int i=0; i<size; i++) { // printing the values one by one by traversing 
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

int * generateArray(int n) { 
	int * arr = malloc( n * sizeof(int) ); // initialising values of integers
	// allocating memory for the new array
    int k; 
	if(arr) {
		for(int i=0; i<n; i++)  // generating array one by one so traversing through 
        {
            scanf("%d",&k);
            arr[i] = k;
        }
	}
	return arr;
}

int main(){
    int *a;
    int n = 10;

    srand(time(NULL)); // creating a random array 

    a = generateArray(n);
    printArray(a,n);

    bubble_sort(a,n);
    printArray(a,n);
    
    free(a);
    return 0;
}