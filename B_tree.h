#include <iostream>

struct node
    {
      std::string data;
      node *left;
      node *right;
    };
    
class B_tree{
  private:
    // creating struct that each one reprsesent a leaf of the tree
    node *root; //first element of the tree (root)
    int size;

  public:
    B_tree(); //constructor
    ~B_tree(); //destructor
    //counter for each tree traversal
    void countPostorder(std::string,node*,int&);
    void countInorder(std::string,node*,int&);
    void countPreorder(std::string,node*,int&);
    //fuction that destroyes the tree completly
    void destroyLeaf(node*);
    // insert element functions
    bool insert(std::string);
    bool insert (std::string,node*);
    bool del(std::string);
    // search element function
     node *search(std::string,node*);
     node *search(std::string);
    // functions that call counters for a given string word
    int inorder(std::string);
    int postorder(std::string);
    int preorder(std::string);
};