#include <iostream>
class Array{
  private:
    std::string *data;
    int size;
    int empty;

  public:

    Array();
    ~Array();

    void insert(std::string);
    void del(char*);
    bool search(std::string);
};