// Heap Sort
 
#include <stdio.h> //introductory 
 

 // function for swapping two elements which will be used later 
void swap(int* p, int* q) // void function requires no value/ variable  to be returned
{
 
    int temp; // initialising temp variable to swap
    temp = *p; // method to swap explained in earlier codes 
    *p = *q;
    *q = temp;
}
 

void heapify(int array[], int n, int k)// void function requires no value/ variable  to be returned
// initialising and taking inputs of an array of integers of size n to heapify a subtree from root k
{
    
    int temp_large = k; // initialsing temp_large, left, right as positions (int) in the binary tree 
    // values of the three variables will be in terms of k which is the parent node 
    int left = 2 * k + 1; 
    int right = 2 * k + 2;
 
 // we need to find the largest among temp_large, left and right. 
 //we will do this by using if else statements
 
    // case 1) If left child is larger than temp_large or the root 
    // there are two conditions for this if statement. They are: left should be less than the number of elements in the array because we need to sort n elements only and left_th element should be larger than temp_large_th element
    if (left <  n && array[left] > array[temp_large])
        temp_large = left;
 // if it is larger then change the position of largest element by changing temp_large
 
    // case 2)If right child is larger than temp_large or the root 
    // conditions similar to case 1
    if (right < n && array[right] > array[temp_large])
        temp_large = right;
 
 
    
    // if k or root is not the largest element after the above process then swap the values 
    if (temp_large != k) {
        swap(&array[k], &array[temp_large]); // accessing the values at the address of the given elements 
        
        heapify(array, n, temp_large); // this will be done for all elements in the array till we get the sorted array
    }
}
 
// Main function to do heap sort
void heap_sort(int array[], int n)
{
    for (int j = n / 2; j >= 0; j--)// to build a max heap
    
    // j can not be negative because it is the position of an element in the array  
    // j will start from the middle position of the array 
    // decrement to reach the 0th posiiton 
        heapify(array, n, j);// carry out heapify function for the loop mentioned above 

    for (int i = n - 1; i >= 0; i--) { // for heap sort 
    // i can not be negative because it is the position of an element in the array  
        // decrement to reach the 0th posiiton 
    // this will be carried out n-1 times because the last element will already be sorted
        swap(&array[0], &array[i]); // using swap function again 
        // Heapify root element to get highest element at root again
        heapify(array, i, 0);
    }
}
 
// A utility function to print array of size n
void print_array(int array[], int n)
{
    for (int i= 0 ; i < n; i++)// printing each element of the sorted array one by one 
    // does not work if i = 1 and i <= n
        printf("%d ", array[i]); 
}
 
// calling all functions 
int main()
{
    int array[] = { 123, 1145, 1, 50, 26, 97, 77 }; // random array 
    int n = sizeof(array) / sizeof(array[0]); // to calculate the number of elements in the array 
    // dividing total space allocation by space allocation of one element 

    heap_sort(array, n);
    printf("Sorted array:\n");
    print_array(array, n);
}
 

 
