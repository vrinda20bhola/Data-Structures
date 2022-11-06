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

/* ================================================== */
//Reversing a linked list
// for revsersing linked list we need to change the pointers. in arrays we need to change the values
NodeAddress reverse(NodeAddress head)
{
	NodeAddress prev= NULL; // initialising and declaring prev and next equal to NULL
	NodeAddress next=NULL;

	while(head!=NULL){ //for the while loop to run head should not be equal to NULL. if it is equal to NULL that means linked list is over
		next= head->next; // storing next 

		//reversing head's pointer 
		head->next=prev;

		//moving pointers and revsersing 
		prev=head;
		head=next;
	}
	head=prev;
	return head;

}

//Printing the linked list
void printLinked_list(NodeAddress head) {
	NodeAddress k; // k and head are variables of datatype NoteAddress 
	printf("Reverse Linked List = ");
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


// calling the functions 
	NodeAddress list;
	list=linked_list(n);
	NodeAddress revhead;
	revhead=reverse(list);
	printLinked_list(revhead);



    freeLinked_List(list);

	return 0;
}
