#include "B_tree.h"

using namespace std;
B_tree::B_tree()
{
  root = nullptr;
  size=0;
}

B_tree::~B_tree()
{
  destroyLeaf(root);
}

// Recursive fuction to delete the given leaf and its kids
void B_tree::destroyLeaf(node *leaf)
{
  if(leaf!=NULL)
  {
    destroyLeaf(leaf->left);
    destroyLeaf(leaf->right);
    delete leaf;
  }
}

//Inserts given word to our tree
bool B_tree::insert(string word)
{
  if(root!=nullptr)
  {
    return insert(word,root);
  }
  else
  {
    root = new node;
    root->data = word;
    root->left = nullptr;
    root->right = nullptr;
    size++;
    return true;
  }
  return false;
}

bool B_tree::insert(string word,node *leaf)
{
  if(word< leaf->data)
  {
    // Creates a new child to the left leaf
    if(leaf->left!=nullptr)
     insert(word, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->data=word;
      leaf->left->left=nullptr;    //Sets the left child of the child node to null
      leaf->left->right=nullptr;   //Sets the right child of the child node to null
      size++;
    }
    return true;  
  }
  else if(word>=leaf->data)
  {
    // Creates a new child to the right leaf
    if(leaf->right!=nullptr)
      insert(word, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->data=word;
      leaf->right->left=nullptr;  //Sets the left child of the child node to null
      leaf->right->right=nullptr; //Sets the right child of the child node to null
    }
    return true;
  }
  return false;
}
// Counter that visits tree leafs in inorder way
void B_tree::countInorder(string word,struct node *leaf,int &count)
{
    if (leaf == NULL)
        return;
 
    // Visits left child first
    countInorder(word,leaf->left,count);
 
    //increases counter of word appearances
    if(word == leaf->data)
      count++;
 
    //Visits  right child
    countInorder(word,leaf->right,count);
}
//Calls recursive function
int B_tree::inorder(string word)
{
  int count=0;
  countInorder(word,root,count);
  return count;
}
// Counter that visits tree leafs in postorder way
void B_tree::countPostorder(string word,node *leaf, int &count)
{
  if (leaf == NULL)
        return;
 
    // Visits left subtree
    countPostorder(word,leaf->left,count);
 
    // Visits  right subtree
    countPostorder(word,leaf->right,count);
 
    if(word == leaf->data)
      count++;
}
//Calls recursive function
int B_tree::postorder(string word)
{
  int count=0;
  countPostorder(word,root,count);
  return count;
}
// Counter that visits tree in preorder way
void B_tree::countPreorder(string word,node *leaf, int &count)
{
   if (leaf == NULL)
        return;
 
    // increases counter if the word matches
    if(word==leaf->data)
    {
      count++;
    }
 
    //Visits left subtree 
    countPreorder(word,leaf->left,count);
 
    // Visits right subtree 
    countPreorder(word,leaf->right,count);
}
//Calls recursive function 
int B_tree::preorder(string word)
{
  int count=0;
  countPostorder(word,root,count);
  return count;
}
// Function that returns true if given string exists on the tree or else false
 node *B_tree::search(string word, node *leaf)
{
  if(leaf!=nullptr)
  {
    if(word==leaf->data)
      return leaf; 
    if(word<leaf->data)
      return search(word, leaf->left);
    else
      return search(word, leaf->right);
  }
  else 
    return leaf;
}
// Calls recursive fuction search(string,node*)
node *B_tree::search(string word)
{
  return search(word, root);
}

bool B_tree::del(string word)
{
  node *a = search(word);
  if(a->left == nullptr && a->right == nullptr)
  {
    delete a;
    size--;
    return true;
  }
  else if (a->left == nullptr  && a->right != nullptr)
  {
    delete a;
    a = a->right;
    size--;
    return true;
  }
  else if(a->left != nullptr && a->right == nullptr)
  {
    delete a;
    a = a->left;
    size--;
    return true;
  }
  else 
  {
    delete a;
    a = a->right;
    size--;
    return true;
  }
  return false;
}