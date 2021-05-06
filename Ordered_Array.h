#include <string>
#include <iostream>
class Ordered_Array
{
  private:
    int size;
    int empty;
    std::string *data;
  
  public:
    Ordered_Array();
    ~Ordered_Array();

    int getSize();

    int binarySearch(int,int,std::string);
    int search(std::string);
    bool insert(std::string);
    bool del(std::string);
    int count(std::string);
    void swap(int,int);
    void order();

};