#include "AVL_tree.h"

using namespace std;

AVL_tree::AVL_tree()
{
  root = nullptr;
  size=0;
}

AVL_tree::~AVL_tree()
{
  //dtr
}
leaf* AVL_tree::newNode(string word)
{
    leaf* newnode = new  leaf;
    newnode ->data = word;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; // new node is initially
                      // added at leaf
    newnode->count++;
    return(newnode);
}
 
// A utility function to get the
// height of the tree
int height(leaf *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}
 
// A utility function to get maximum
// of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
leaf *AVL_tree::rightRotate(leaf *y)
{
    leaf *x = y->left;
    leaf *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Return new root
    return x;
}
 
// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
leaf *AVL_tree::leftRotate(leaf *x)
{
    leaf *y = x->right;
    leaf *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int AVL_tree::getBalance(leaf *N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}
void AVL_tree::insert(string word)
{
  leaf *b;
  b = insert(root, word);
  size++;
  if(size==1)
  {
    root=b;
  }
}
// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
leaf* AVL_tree::insert(leaf* newnode, string word)
{
    /* 1. Perform the normal BST insertion */
    if (newnode == nullptr)
        return(newNode(word));
 
    if (word < newnode->data)
        newnode->left = insert(newnode->left, word);
    else if (word > newnode->data)
        newnode->right = insert(newnode->right, word);
    else // Equal keys are not allowed in BST
    {
        newnode->count++;
        return newnode;
    }
    /* 2. Update height of this ancestor node */
    newnode->height = 1 + max(height(newnode->left),
                        height(newnode->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(newnode);
 
    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && word < newnode->left->data)
        return rightRotate(newnode);
 
    // Right Right Case
    if (balance < -1 && word > newnode->right->data)
        return leftRotate(newnode);
 
    // Left Right Case
    if (balance > 1 && word > newnode->left->data)
    {
        newnode->left = leftRotate(newnode->left);
        return rightRotate(newnode);
    }
 
    // Right Left Case
    if (balance < -1 && word < newnode->right->data)
    {
        newnode->right = rightRotate(newnode->right);
        return leftRotate(newnode);
    }
 
    /* return the (unchanged) node pointer */
    return newnode;
}
int AVL_tree::getCount(string word)
{
  leaf *res;
  res = search(root,word);
  if( res == nullptr)
    return 0;
  cout<<res->data;
  return res->count;
}
leaf *AVL_tree::search(leaf *first,string word)
{
  if (first != nullptr)
  {
    cout<<first->data<<" ";
    if(first->data == word)
    {
      return first;
    }
    return search(first->left,word);
    return search(first->right,word);
  }
    return nullptr;
} 
// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void AVL_tree::preOrder(leaf *first)
{
    if(first != nullptr)
    {
        cout << first->data << " ";
        preOrder(first->left);
        preOrder(first->right);
    }
}

void AVL_tree::preOrder()
{
  preOrder(root);
}