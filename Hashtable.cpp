#include "Hashtable.h"

using namespace std;

Hashtable::Hashtable()
{
  capacity = 2000;
  size = 0;
  table = new cell[capacity];
}

Hashtable::~Hashtable()
{
  //dtr
}

int Hashtable::hashFunction(string word,int flag)
{
  int count=1;
  for(char const s:word)
  {
    count = count + int(s);
  }
  return (count+(20+flag))%capacity;
}

void Hashtable::insert(string word)
{
  int tries=-1,location;
  bool flag=false;
  while (flag == false)
  {
    tries++;
    location = hashFunction(word,tries);
    if((table[location].data).compare( word)==0)
    {
      table[location].count += 1;
      flag = true;
      size++;
    }
    else
    {
      if(table[location].data.empty())
      {
        table[location].data = word;
        table[location].count ++;
        size++;
        flag = true;
      }
    }
  }
}

int Hashtable::search(string word)
{
  int tries = 0,res = -1;
  bool flag = false;
  int location;
  while (flag == false)
  {
    location = hashFunction(word,tries);
    if((table[location].data).compare(word)==0)
    {
      flag = true;
      res =  location;
    }
    tries++;
  }
  return res;
}

int Hashtable::count(string word)
{
  int index = search(word);
  return table[index].count;
}
void Hashtable::print()
{
 for(int i=0;i<capacity;i++)
 {
  if(!table[i].data.empty())
  {
    cout<<table[i].data<<" ";
  }
 }
}