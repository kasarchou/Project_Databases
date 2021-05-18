#include "Array.h"
#include <string>
#include <cstring>
 using namespace std;
Array::Array()
{
  empty =10000;
  data = new string[empty];
  size = -1 ;
}
Array::~Array()
{
  //dtr
}

int Array::getSize()
{
  return size + 1;
}

string Array::getData(int i )
{
  return data[i];
}
// Inserts given word  to the array
void Array::insert(string word)
{
  if (size <= empty)
  {
    size++;
    data[size] = word;
  }
  else // We increase the size of the array if it is full!
  {
    cout<<"increased"<<endl;
    empty+=10000;
    string *new_data = new string[empty];
    for(int i=0;i<=size;i++) // Copying the words to the new array
      new_data[i] = data[i]; 
    delete [] data;
    data = new_data; // We assign the data pointer to our saved data.
    size++;
    data[size] = word;
  }
} 

int Array::search(string word)
{
  int index= -1;
  for(int i=0;i<=size;i++)
  {
    if(data[i].compare(word)==0)
    {
      index = i;
      return index;
    }
  } 
  return index;
}
int Array::count(string word)
{
  int count=0;
  for(int i=0;i<=size;i++)
  {
    if(data[i].compare(word)==0)
    { 
        count = count+1;
    }
  } 
  return count;
}

bool Array::del(string word)
{
  int index;
  index = search(word);
  if(index == -1)
    return false;
  else
  {
    data[index] = data[size];
    data[size]="";
    size--;
    return true;
  }
}