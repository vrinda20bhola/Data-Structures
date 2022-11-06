
#include <math.h>
#include <stdio.h>
 
/* Function to sort an array using insertion sort*/
void insertion_sort(int array[], int n) // using void so that we dont have to return any value
// initialising an array of "n" numbers 
{
    int start, wall, i; // initialising three integers called start, wall and i. 
    for (start = 1; start < n; start++) { // using for loop to give position to wall and ith element of the array
        wall = array[start];
        i = start - 1;
 
        // moving elements of the array that are greater that wall to one position ahead of their current position
        while (i >= 0 && array[i] > wall) { // using while loop if the ith element is greater than wall element. If
            array[i + 1] = array[i]; 
            i = i - 1; // reducing the value for insertion sort to take place
        }
        array[i + 1] = wall; // remains same by taking value of the start element if while loop condition is not met. If while loop condition is met then value is changed.
    }
}
// the array has been sorted by insertion sort
// function to print the sorted array
void print_array(int array[], int n) // printing an array of n elements 
{
    int j; // initialising j whcih will traverse through the array to print values
    for (j = 0; j < n; j++) // j will start from 0th element and go on until j = last element i.e n-1th (j<n)
        printf("%d ", array[j]); // printing values of the array one by one of
    printf("\n"); // leaving a line 
}
 
int main()
{
    int array[] = { 100, 111, 30, 45, 6789 }; // any random array 
    int n = sizeof(array) / sizeof(array[0]); // size of array = n 
 
    insertion_sort(array, n); // executing the two functions coded above 
    print_array(array, n);
 
    return 0;
}
