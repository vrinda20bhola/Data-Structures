// Binary Search Trees
// Professor's code
// incomplete code with errors 

struct nodeType { // creating a structure with three variables 
	int val; 
	struct nodeType * left;  // smaller // left pointer to smaller numbers 
	struct nodeType * right; // larger // right pointer to larger numbers
};

typedef struct nodeType * NodeAddress; // making a shortcut for accessing the above structure 

/* EXAMPLE 

4, left: 2, right: 7

2, left: 1, right: 3

7, left: 5, right: 9

1, 3, 5, 9 -> left: NULL, right: NULL

*/

NodeAddress search(NodeAddress root, int val) { // search of datatype noteaddress with two inputs: root (datatype noteaddress), val (int which needs to be searched for)
	if(root==NULL) return NULL; // if root = NULL then the BST is empty so return null
// the following elimenates half of the linked list (left or right part of BST)
	if      ( val < root->val ) { return search(root->left , val);} // if val is less than the root value then go to the left side of the BST 
	else if ( val > root->val ) { return search(root->right, val);} // if val is more than the root value then go to the right side of the BST 
	else                        { return root;}
	// if value is not lesser or greater than root then it must be equal to to the root in which cases it returns the root 
}

// another way of coding up lines 24-31 or the search function 
// complicated 
NodeAddress search2(NodeAddress root, int val) {
	return root?((val==root->val)? root : (  ( val < root->val )? search2(root->left , val): search2(root->right, val)  ) ): NULL;
}

// inserting a value to the BST 
// the datatype of the following varaibles is noteaddress
NodeAddress insert(NodeAddress root, int val) {
	if(root==NULL) {return createNode(val);} // if root is equal to NULL then we need to insert the value there by creating another node 
	if      ( val < root->val ) { root->left  = insert(root->left , val);} // if value is lesser than the root then move to the left and carry out the process again till the time root = NULL with the (changed) root and (to be insterted) value as inputs
	else if ( val > root->val ) { root->right = insert(root->right, val);}
// if value is greater than the root then move to the right and carry out the process again till the time root = NULL with the (changed) root and (to be insterted) value as inputs
	return root; 
}

// another way of inserting a value 
NodeAddress insert2(NodeAddress root, int val) {
	if(root==NULL) {return createNode(val);}

	if ( val < root->val ) { 
		if(root->left) return insert2(root->left, val);
		else root->left = createNode(val);
		return root->left;
	}
	else if ( val > root->val ) { 
		if(root->right) return insert2(root->right, val);
		else root->right = createNode(val);
		return root->right;
	}
	
	return root;
}
