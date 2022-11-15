#include <stdio.h>
#include <stdlib.h>
#include <string.h> // introductory 

struct node { // creatng a structure with data types int and pointer 
// prof's codes 
	int val;
	struct node * next;	
};

typedef struct node * NodeAddress; //this will be used as a shortcut instead of referring to the whole struct again and again 
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




//Printing the linked list
void printLinked_list(NodeAddress head) {
	NodeAddress k; // k and head are variables of datatype NoteAddress 
	printf("Linked List = ");
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


/* ================================================== */
//To find out the length of the linkedlist and then find the half of the total length 
void half_linkedlist(NodeAddress head) // head is of datatype noteaddress
{
  NodeAddress fast; // initialsing two variables fast and slow of the datatypes noteaddress
  NodeAddress slow;  
  // As the name suggests, fast will move faster than slow. It will move twice as fast and when it reaches NULL i.e the end of the linekd list, slow will reach the middle of the linked list which is what we need to half the linked list 
  // starting point of both slow and fast will be head
  fast = head;
  slow = head;
  
  // the loop will carry on till the time fast is equal to null i.e the linked list is over. When fast = Null, slow will be equal to half.
  while(fast!=NULL)
  {
  printf("%d\n",slow->val); // printing the values of slow till the middle of the linked list 
  
  // incrementing the fast twice whereas incrementing slow only once to reach half 
   fast = fast -> next; // going on to the next value/pointer
   fast = fast -> next;
   slow = slow->next;
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

// calling fucntions
	NodeAddress list;// to store the head of the initial linked list
	list=linked_list(n);// creating a linked list and storing the head in the list
   printLinked_list(list); // printing the linked list that was entered 
  half_linkedlist(list); // printing the half linked list 
  freeLinked_List(list); // free all the memory 
  return 0;
}