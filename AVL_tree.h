#include <iostream>
#include <string>

struct leaf
{
  std::string data;
  int height;
  leaf *left;
  leaf *right;
  int count;
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
    leaf *leftRotate(leaf*);
    leaf *rightRotate(leaf*);
    leaf* newNode(std::string);
    void insert(std::string);
    leaf* insert(leaf*,std::string);
    void del(std::string);
};