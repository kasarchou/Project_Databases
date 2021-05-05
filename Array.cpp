#include "Array.h"
#include <string>
#include <cstring>
 using namespace std;
Array::Array()
{
  empty =5000;
  data = new string[empty];
  size = -1 ;
}
Array::~Array()
{
  //dtr
}
void Array::insert(string word)
{
  if (size < empty)
  {
    size++;
    data[size] = word;
    cout<<data[size]<<endl;
  }
  else
  {
    empty+=5000;
    string *new_data = new string[empty];
    new_data = data; 
    delete [] data;
    data = new_data;
    size++;
    data[size] = word;
    cout<<data[size]<<endl;
  }
} 

bool Array::search(string word)
{
  for(int i=0;i<=size;i++)
  {
    if(word == data[size])
      return true;
  }
  return false;
}