#include <iostream>
#include <string>
#include <cstring>

struct cell
{
  std::string data;
  int count=0;
};
class Hashtable{
  // Variables of class
  private :

    cell *table;
    int size;
    int capacity;
  
  public:

    Hashtable(); //Empty Constructor
    ~Hashtable(); //Destructor

    int hashFunction(std::string,int);
    void insert(std::string);
    int search(std::string);
    int count(std::string);
    bool increaseSize();
    void print();
    //Functions of class
};