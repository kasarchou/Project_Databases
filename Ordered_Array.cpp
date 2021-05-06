#include "Ordered_Array.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor of array.
Ordered_Array::Ordered_Array()
{
  empty=10000;
  size=-1;
  data = new string[empty];
}
// Destructor  wipes out data array
Ordered_Array::~Ordered_Array()
{
  delete[] data;
}
// Gets number of the words in the array.
int Ordered_Array::getSize()
{
  return size;
}
// Inserts a word to the array.
bool Ordered_Array::insert(string word)
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
  return true;
}

// Function to swap values s1 and s2.
void Ordered_Array::swap(int s1,int  s2)
{
  string temp;
  temp = data[s1];
  data[s1] = data[s2];
  data[s2] = temp;

}
// We order the array using bubblesort from A-Z
void Ordered_Array::order()
{
  for (int i=0;i<=size;i++)
  {
    for (int j=size;j>i;j--)
      if (data[j]<data[j-1])
        swap(j,j-1);
  }
}

// Algorithm for the recursive binary search of the ordered array.
int Ordered_Array::binarySearch( int first, int last,string word)
{
   int middle;
   if(last >= first)
   {
      middle = (first + last)/2;
      //Checking if the element is present at middle loc
      if(data[middle] == word)
      {
         return middle+1;
      }

      //Checking if the search element is present in greater half
      else if(data[middle] < word)
      {
         return binarySearch(middle+1,last,word);
      }

      //Checking if the search element is present in lower half
      else
      {
         return binarySearch(first,middle-1,word);
      }
   }
   return -1;
}


// We do a binary search on our ordered array to find the requested string element.
int Ordered_Array::search(string word)
{
  return binarySearch(0,size, word);
}

// We search for the  element and count left and right from it for all the words matching.
int Ordered_Array::count(string word)
{
  int count=0;
  int index = search(word);
  // Checks right fromn the index found.
  for(int i=index;data[i]==word;i++)
    count++;
  // Checks left from the index found.
  for(int i=index-1;data[i]==word;i--)
    count++;
  return count;
}

// Deletes an element from the word given.
// Returns true if successful or false if not.
bool Ordered_Array::del(string word)
{
  int index = search(word); // Gets the position of the word in the array.
  if (index!=-1)
  {
    // Covers the empty spot of the array and reduces size.
    for(int i =index;i<size;i++)
      data[i] = data[i+1];
    data[size]="";
    size--;
    return true;
  }
  return false;
}