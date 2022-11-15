// selection sort using linked lists
// professor's code


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node { // using struct to initialise val and node 
// creating a structure for nodes to be used in linked list 
	int val; // value of the node 

	struct node * next;	// a node pointing to the next node and using struct
};typedef struct node * NodeAddress; // creating a new data type called NodeAddress which is the address of the node


/* ================================================== */
void swap(int *x, int *y) {  // swapping integer values 
// swap function will be used later in the code
	int temp; // temp initialised as int 
	temp = *x;
	*x = *y;
	*y = temp;
}


/* ================================================== */
int * generateArray(int n) { // function to create an array of length of n
	int * t = malloc( n * sizeof(int) ); // allocating memory to integer 
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;} // taking random values 
	}
	return t;
}

NodeAddress linkedListFromArray(int * a, int n) { // datatype nodeAddress  
	int i; // initialsiing i, head, temp
	// explained creating a linked list in creation_LL.c code 
	// directly jumping to selection sort code 
	NodeAddress head = NULL;
	NodeAddress temp = NULL;

	// special case for head
	if(n>0) {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}

void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}

/* ================================================== */
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

void printLinkedList(NodeAddress head) {
	NodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}

/* ================================================== */

int findIndexOfMax(int *a, int n) {
	int imax; // this will contain the address of the largest element encountered.
	int i; 

	// error case if there are no elements in the list
	if(n<1) {return -1;}

	imax = 0; // I am assuming that a[0] is the max element
	for(i=1; i<n; i++) { // finding the max element using for loop 
		if( a[i] > a[imax] ) {
			imax = i;
		}
	}
	return imax;
}

void selectionSort(int *a, int n) {
	int i, imax, t;

	for(i=n; i>1; i=i-1) { // for loop to sort all elements 
	// we can also go from start to end by incrementing 
		imax = findIndexOfMax(a, i); // swapping elements 
		t = a[imax]; 
		a[imax] = a[i-1];
		a[i-1] = t;
		// or we can use the swap function previously defined
	}
}



/* ================================================== */
int main(int argc, char **argv) { // calling all functi0ons 
	int * a;
	int n = 10;
	int maxindex;
	int p, q;
	NodeAddress list;

	srand(time(NULL)); // taking random integers 

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
	selectionSort(a,n);
	printArray(a,n);

// not needed idk why prof wrote this 
	p = 5;
	q = 10;
	swap(&p, &q);
	printf("%d\n", p);


	free(a);
	freeLinkedList(list);

	return 0;
}