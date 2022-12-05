// AVL trees 


// introductory 
#include<stdio.h>
#include<stdlib.h>
 

struct Node // using struct to initialise a, height and nodes of subtree
// creating a structure for nodes to be used in the AVL tree 
{
    int a;
    struct Node *left;
    struct Node *right;
    int height;
}; typedef struct Node* nodeAddress; // shortcut 

 // comparing two intgers to get the larger one 
int compare(int p, int q)
{
    if(p>q)
    return p;
    else
    return q;
}


// finding the height of the tree 
int height(nodeAddress N) 
{
    if (N == NULL)  // if N is null then no change
        return 0;
    return N->height; // return the changed height 
}
 

 
// creating a new node with empty left and right children and height 1 
nodeAddress new_node(int a)
{
    nodeAddress node = (nodeAddress)malloc(sizeof(struct Node)); 
    // allocating space for new node 
    node->a   = a;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // height of the new node will be 1
    
    return(node);
}
 // calculating balancing factor 
int balancing_factor(nodeAddress N)
{
    int n;
    n = height(N->left) - height(N->right); //formula = left subtree - right subtree
    if (N == NULL)
        return 0;
    return n; // returning balancing factor 
}

// right rotate the AVL tree to balance it if it is unbalanced  
nodeAddress right_rotate(nodeAddress q)
{
    nodeAddress p = q->left; // what it will point towards 
    nodeAddress t = p->right;
 
    // rotating the tree 
    p->right = q;
    q->left = t;
 
    // heights change 
    q->height = compare(height(q->left),height(q->right)) + 1; 
    p->height = compare(height(p->left),height(p->right)) + 1;
 
  
    return p; // which is the new root after rotation 
}
 
// repeat same thing for left rotate
nodeAddress left_rotate(nodeAddress p)
{
    nodeAddress q = p->right;
    nodeAddress t = q->left;
 

    q->left = p;
    p->right = t;
 

    p->height = compare(height(p->left),  height(p->right)) + 1;
    q->height = compare(height(q->left),height(q->right)) + 1;
    return q;
}
 

 
// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
nodeAddress insert(nodeAddress node, int a) {
    
    if (node == NULL) // just insert the value a if the node is null
        return(new_node(a)); 
 
    if (a < node->a) // if node is not empty then
        node->left  = insert(node->left, a); // call the function again 
    else if (a > node->a)
        node->right = insert(node->right, a);
    else // Equal values are not allowed in BST so = case not considered 
        return node;
 
     // changing height 
    node->height = 1 + compare(height(node->left),height(node->right));
 
 // initialising the value returned from balancing factor 
    int n = balancing_factor(node);
 
 // there are 4 cases if the AVL tree is unbalanced
 // unbalanced if balancing factor is not -1,0 or 1
  
    // Right Right Case
    if (n < -1 && a > node->right->a) // two conditions to execute if statement  
        return left_rotate(node);
        
    // Left Left Case
    if (n > 1 && a < node->left->a)
        return right_rotate(node);

    // Left Right Case
    if (n > 1 && a > node->left->a)
    {
        node->left =  left_rotate(node->left);
        return right_rotate(node);
    }
 
    // Right Left Case
    if (n < -1 && a < node->right->a)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
}
 
void print(nodeAddress node)
{
    if(node != NULL) // if node has a value then print it 
    {
        printf("%d ", node->a);
        print(node->left);
        print(node->right);
    }
}
 

int main() // calling all functions 
{
  nodeAddress root = NULL;
 

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
 
  print(root);
 
  return 0;
}