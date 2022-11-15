// BINARY SEARCH TREE
// CREATE AND INSERT

#include <stdio.h>
#include <stdlib.h> // introductory 
 
struct node { //creating a structure with val, left and right pointers 
    int val;
    struct node *left; // left pointer to smaller numbers 
    struct node*right; // right pointer to larger numbers
}; typedef struct node * NodeAddress; // making a shortcut for accessing the above structure 
 
// creating or adding a new node to BST 
 NodeAddress Add_Node(int val) // add the integer value of val
{
     NodeAddress new = malloc(sizeof(struct node)); // allocating memory for the new node which is of size node 
    new->val = val; // adding value to the new node created 
    new->left =NULL;  // left of new node will be empty 
    new->right = NULL; // right of new node will be empty 
    return new; 
}
 
// didnt understand, had to copy to run the code 
// will meet with TA to understand the following lines 25- 32
void inorder(NodeAddress root) // what is inorder? why is the code not running without this function ?
{
    if (root != NULL) { // if root is not equal to NULL then do the following 
        inorder(root->left); // left side of node 
        printf("%d \n", root->val); // print the value 
        inorder(root->right); // right side of node 
        // sorting the binary tree?
    }
}
 
// inserting a new node to an existing BST
NodeAddress insert_node(NodeAddress node, int val)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return Add_Node(val); // if node = NULL then add a node with value there by previously defined function
 
    // if node is not equal to NULL then traverse down the tree to find where node = NULL
    if ( val < node->val) 
        node->left = insert_node(node->left, val); // if value is lesser than the root then move to the left and carry out the process again till the time root = NULL with the (changed) root and (to be insterted) value as inputs
    else if (val > node->val)
        node->right = insert_node(node->right, val); // repeat the same thing with greater than case
    return node;
}

// in an existing BST, delete val and return the new root 
NodeAddress delete_node(NodeAddress root, int val)
{
// if the BST is empty then there is nothing to delete so return root 
    if (root == NULL)
        return root; 
  

    // if the value to be deleted is lesser than the root then we traverse to the left subtree
    if (val < root->val)
        root->left = delete_node(root->left, val); // repeat the process 

//  if val is greater than root then go to the right subtree
    else if (val > root->val)
        root->right = delete_node(root->right, val);// repeat the process 
  
  // if the val is not lesser or greater than the root then it must be equal to the root and hence must be deleted 
    else {
        // now we will have to delete the following nodes of subtrees along with the root to be deleted becasue the subtrees cannot exist without the parents 
        // so we have to free all the following nodes 
        // we will have two cases 
        
        // case 1) node with only one child or no child
        if (root->left == NULL) {
           NodeAddress temp; // creating a new variable temp of datatype NodeAddress
           temp = root->right; // if there is any node to the right of root then free it 
            free(root); // freeing the memory
            return temp;
        }
        else if (root->right == NULL) {
            NodeAddress temp; // creating a new variable temp of datatype NodeAddress
            temp = root->left;// if there is any node to the left of root then free it 
            free(root); // freeing the memory
            return temp;
        }

    }
    return root;
}
// calling all functions 
int main()
{
    struct node* root = NULL;
    root = insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 2);
    insert_node(root, 4);
    insert_node(root, 7);
    insert_node(root, 6);
    insert_node(root, 8);
 
   
    inorder(root);
  
    printf("\nDelete 2\n");
    root = delete_node(root, 2);
    
    inorder(root);

  
    return 0;
}


