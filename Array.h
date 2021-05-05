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
    bool del(std::string);
    int search(std::string);
    int count(std::string);
};