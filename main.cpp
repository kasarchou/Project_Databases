#include <iostream>
#include <fstream>
#include <cstring>
#include "Array.h"
int main() {
  using namespace std;
  string filename,word;
  Array a;
  cout << "Give me a file name (.txt): ";
  cin>>filename;
  ifstream file;
  file.open(filename.c_str(),ios::in);
  if (file.is_open())
  {
    while(file >> word)
    {
      for(size_t i = 0; i<word.length(); ++i)
      {
        if(ispunct(word[i]))
          word.erase(i--, 1);
      }
      a.insert(word);
    }
  }
  else
  {
    printf("File  Error!");
  }

}