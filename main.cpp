// Libraries we used
#include <iostream>
#include <fstream>
#include <cstring>
#include "Array.h"
#include "Ordered_Array.h"

//............................................MAIN................................................
int main() {
  using namespace std;
  string filename,word;
  int res;
  Array a;
  Ordered_Array b;
  cout << "Give me a file name (.txt): ";
  cin>>filename;
  ifstream file;
  // We try to open the file 
  file.open(filename.c_str(),ios::in);
  // If the file opens successfully then...
  if (file.is_open()) 
  {
    while(file >> word)
    {
      for(size_t i = 0; i<word.length(); ++i)
      {
        // ispunct() removes the punctuation from the string word
        if(ispunct(word[i]))
          word.erase(i--, 1);
      }
      a.insert(word);
      b.insert(word);
      
    }
    b.order();
  }
  else // Prints error message in case  of failure while openning file!
  {
    printf("File  Error!");
  }

}