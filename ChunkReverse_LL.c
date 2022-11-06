// REVERSING A LINKED LIST 
// created a linked list first which is then reversed 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node { // creating a structure for nodes to be used in linked list 
	int val; // value of the node 
	struct node * next;	// a node pointing to the next node and using struct
};
typedef struct node * NodeAddress; // creating a new data type called NodeAddress which is the address of the node


//Creating a linked list

NodeAddress linked_list(int n) { // Noteaddress is the data type of the function which will create a linked list of n elements 
	int j; // initialising an integer j 
	NodeAddress head = NULL; // from prof's code. 
	NodeAddress temp = NULL; // taking two variables of datatype NodeAddress equal to NULL
	int x=0; 

	// special case for head
	if(n>0) {
		head = malloc( sizeof(struct node) ); // allocating memory equal to size of the node to head
		printf("Enter the elements \n"); // taking inputs from user for values of linked list
		scanf("%d",&x);
		head->val  = x;  // value of head = x
		head->next = NULL; // next to node of head is null or empty 
		temp = head; // equating temp to head to use it further 
	}


	for(j=1; j<n; j++) { // from prof's code 
	// using for loop where j is starts from the 1st position and goes on till n-1 (j<n)
	// it starts from one because head is the takes the 0th poisition
		temp->next = malloc( sizeof(struct node) ); // allocating memory to temp next of the size of a node 
		temp = temp->next;
		scanf("%d",&x); 
		temp->val = x; // assigning values to the nodes
		temp->next = NULL; // temp next should be null first and then it will be assigned a value when loop runs again
	}

	return head;
}

//Reversing a chunk of the list 
NodeAddress Chunk_reverse(NodeAddress head) // of datatype noteaddress
{
   printf("What is the chunk size to be reversed \n");
   int size; // size of chunk
   scanf("%d",&size); // input value of chunk size by user 

   NodeAddress prev= NULL;
   NodeAddress next=NULL;
   NodeAddress start=head; //initiliasing three variables of datatype noteaddress 
 
   for(int i=0; i<size && head!=NULL; i++) // using for loop where i starts from 0 and goes on till i<size , for the loop to run, head should not be equal to NULL, i is incremented by one after a loop is completed
   {
       // repeating code for reversing a linked list
       next=head->next;
 
       //reversing current node's pointer
       head->next=prev;
 
       //moving pointers ahead
       prev=head;
       head=next;
   }
  // chunk of size inputted has been reversed
   // Now, the head and next points towards the (size+1)th element 
   //'start' points to the the first element of the inital linked list(head).
   // (size+1)the element to the last element of the linked list will remain the same
   start->next=head;
   return prev; 
   // if we return head, it is an error as we get the linked list from the (size+1)th element 
}
 

//Printing the linked list
void printLinked_list(NodeAddress head) {
	NodeAddress k; // k and head are variables of datatype NoteAddress 
	printf("Chunk reverse Linked List = ");
	for(k=head; k!=NULL; k=k->next) { // printing elements of the linked list one by one 
	// k starts from head position and goes on till k = null 
		printf( k==head?"%d":", %d", k->val);
	}
	printf(".\n");
}

//To free the space used by the linked list
// prof's code 
// we have to free all the space that we allocated using malloc
void freeLinked_List(NodeAddress head) {
	NodeAddress prev; // prev is a variable of datatype NoteAddress
	while(head) { // while loop to free memory
		prev = head;
		head = head->next;
		free(prev);
	}
}



int main(int argc, char **argv) {
	printf("Enter the size\n"); // taking the input of size of the linked list from the user
    int n;
    scanf("%d",&n);
    
	if(n<=0){ // can not take size less than and equal to 0 
	// constraint 
        printf("Size should be greater than 0");
        return 0;
    }

// calling all functions 
NodeAddress list;// storing the head of the initial linked list
   list=linked_list(n); 
   NodeAddress Chunk_reverse_head;
   Chunk_reverse_head=Chunk_reverse(list);
   printLinked_list(Chunk_reverse_head);
 
   freeLinked_List(list);
 
   return 0;
}
