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
    newnode->count = 1;
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
        ++newnode->count;
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
  return res->count;
}
leaf *AVL_tree::search(leaf *first,string word)
{
  leaf *res;

  if(first!=nullptr)
  {
    if(first->data.compare( word)==0)
    {
      return first;
    }
     res = search(first->left,word);
     if(res!=nullptr)
      return res;
     res = search(first->right,word);
     if (res!= nullptr)
      return res;
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

leaf *AVL_tree::minVal(leaf* node) 
{ 
    leaf* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != nullptr) 
        current = current->left; 
  
    return current; 
} 
  
// Recursive function to delete a node 
// with given key from subtree with 
// given root. It returns root of the 
// modified subtree. 
leaf* AVL_tree::del(leaf* node, string word) 
{ 
      
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (node == nullptr) 
        return node; 
  
    // If the key to be deleted is smaller 
    // than the root's key, then it lies
    // in left subtree 
    if ( word < node->data ) 
        node->left = del(node->left, word); 
  
    // If the key to be deleted is greater 
    // than the root's key, then it lies 
    // in right subtree 
    else if( word > node->data ) 
        node->right = del(node->right, word); 
  
    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (node->left == nullptr) ||
            (node->right == nullptr) ) 
        { 
            leaf *temp = node->left ? 
                         node->left : 
                         node->right; 
  
            // No child case 
            if (temp == nullptr) 
            { 
                temp = node; 
                node = nullptr; 
            } 
            else // One child case 
            *node = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            leaf* temp = minVal(node->right); 
  
            // Copy the inorder successor's 
            // data to this node 
            node->data = temp->data; 
  
            // Delete the inorder successor 
            node->right = del(node->right, temp->data); 
        } 
    } 
  
    // If the tree had only one node
    // then return 
    if (node == nullptr) 
    return node; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, 
    // then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && 
        getBalance(node->left) >= 0) 
        return rightRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && 
        getBalance(node->left) < 0) 
    { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Right Case 
    if (balance < -1 && 
        getBalance(node->right) <= 0) 
        return leftRotate(node); 
  
    // Right Left Case 
    if (balance < -1 && 
        getBalance(node->right) > 0) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    return node; 
} 