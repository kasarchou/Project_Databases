#include <iostream>
#include <string>

struct leaf
{
  std::string data;
  int height;
  leaf *left;
  leaf *right;
  int count = 0;
};

class AVL_tree
{
  private:
    leaf *root;
    int size;
  public:
    AVL_tree();
    ~AVL_tree();

    int getBalance(leaf*);
    void preOrder();
    void preOrder(leaf*);
    leaf *search(leaf*,std::string);
    int getCount(std::string);
    leaf *minVal(leaf*);
    leaf *leftRotate(leaf*);
    leaf *rightRotate(leaf*);
    leaf* newNode(std::string);
    void insert(std::string);
    leaf* insert(leaf*,std::string);
    leaf *del(leaf*,std::string);
};