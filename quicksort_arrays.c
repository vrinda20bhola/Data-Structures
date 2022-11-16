// quick sort using arrays

#include<stdio.h> // introductory 

void quicksort(int array[100],int i,int n){
    // a random empty array is created, i  is the position of the array, there are n elements 
   int j, pivot; // initialising variables which will be used 
   int temp;
   if(i<n){ // if statement will carry out if i is less than the  number of elements 
   
      pivot=i; // settting pivot as the i_th element to start with 
      j=n; // setting j as the nth element 
      
      while(i<j){
         while(array[i]<=array[pivot] && i<n) // while loop will have two conditions. 
         // if the i_th element is less than pivot element and less than total number of elements then increment i 
         i++;
         
         while(array[j]>array[pivot]) // while loop will execute if j_th element is less than pivot element 
         j--; // decrements j 
         
         if(i<j){ // swapping elements to sort it using temp 
         // smaller swapping 
         
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
      }
      }
      // swapping pivot and j element 
      // main swapping 
      temp= array[pivot];
      array[pivot]=array[j];
      array[j]=temp;
      
      quicksort(array,i,j-1); // calling quick sort again to carry it out properly 
      quicksort(array,j+1,n); // without this does not happen
      // dont know why we use this, had to copy from net to run this code properly 
   }
}
// calling functions 
int main(){
   int i, n, array[100];
   printf("No of elements: ");
   scanf("%d",&n);
   
   printf("Enter %d elements: ", n);
   // taking inputs from user individually
   for(i=0;i<n;i++)
   scanf("%d",&array[i]);
   
   quicksort(array,0,n-1);
   
   printf(" Sorted array: ");
   for(i=0;i<n;i++) // printing elements one by one
   printf(" %d",array[i]);
   
   return 0;
}
