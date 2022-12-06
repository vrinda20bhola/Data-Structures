// Insertion sort using linked list 
// only foussed on insertion sort's function and not the rest 

NodeAddress insertionSort(NodeAddress head, NodeAddress done) // head is the first element and done is the element that is sorted 
{
	NodeAddress current = head;
	// current traverses through the linked list and is initialised as head of data type node address 
  
    while (current != NULL) // if current equals null then the linked list ends i.e all elements have been traversed 
	{
        NodeAddress next = current->next; // go to the next node 
        sortedInsert(current, done);// sortedInsert takes the pointer current and inserts the element in sorted
        current = next; // updating the value of next for the next step in while loop
    }
    // Update head to point to the start of the sorted linked list and return it
    head = done;
	return head; //returning head
}


void sortedInsert(NodeAddress newNode, NodeAddress done)
{
    
    // two cases: when done is equal to NULL and when it is not equal to NULL
    if (done == NULL || done->val >= newNode->val)  // comparing values of done and new node
	{
        newNode->next = done; 
        done = newNode;
    }
    else 
	{
        NodeAddress i; // initialising a variable i of datatype node address 
        i= done; 
        // Locate the node before the point of insertion
        while (i->next != NULL && i->next->val < newNode->val) 
		{
            i= i->next;
        }
        newNode->next = i->next;
        i->next = newNode;
    }
}
