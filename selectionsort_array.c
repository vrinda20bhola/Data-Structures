// selection sort using array 
#include <stdio.h>
 
void swap(int *swap_1, int *swap_2) // creating function to swap the values later 
// using pointers to swap the values as we are sending the address of to the swap function.
{
    int temp; // initliasing temp as an integer
    temp = *swap_1; // swaping using a third variable 
    *swap_1 = *swap_2;
    *swap_2 = temp;
}
 
void selection_Sort(int array[], int n) // an array of n elements 
{
    int i, j, min; // initialising three varaibles as integers
 

    for (i = 0; i < n-1; i++) // using for loop to go through the whole array 
    {

        min = i; // let min = i for the start
        for (j = i+1; j < n; j++) // finding the minimum element in the unsorted array 
        // we start from i+1 because before that the array is sorted 
          if (array[j] < array[min]) // comparing the values 
            min = j; // change in minimum value 

           if(min != i) // swaping the minimum value with the unsorted element, i, after the whole list has been traversed 
            swap(&array[min], &array[i]); 
            
            //1.  NOT WORKING to swap the values 
            //temp = array[min_idx];
            //array[min_idx] = array[i];
            //array[i] = temp;
            
            //2. if i do array[min_idx] = array[i]; to swap the values
            //the array is not sorted properly. 
    }
}
 
/* Function to print an array */
void printArray(int array[], int n)
{
  // printing the sorted array one by one 
    for (int k=0; k < n; k++) // using for loop to traverse through the array and print the elements 
        printf("%d ", array[k]);
}
 

int main()
// when i change the name of function to blah etc it gives some weird error  
{
    int array[] = {11, 56, 78, 32, 67}; // random array
    int n = sizeof(array)/sizeof(array[0]); // value of n is equal to the size of the array 
    
    // calling all functions
    selection_Sort(array, n);
    printf("Sorted array:");
    printArray(array, n);
    return 0;
}