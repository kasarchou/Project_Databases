// Libraries we used
#include <iostream>
#include <fstream>
#include <cstring>
#include "Array.h"
#include "Ordered_Array.h"
#include "B_tree.h"
#include "AVL_tree.h"

//............................................MAIN................................................
int main() {
  using namespace std;
  string filename,word;
  int res;
  // Declare  our databases
  Array a;
  Ordered_Array b;
  B_tree c;
  AVL_tree d;
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
      c.insert(word);   
      d.insert(word);
    }
    //c.del("Vinci");
    d.preOrder();
    cout<<d.getCount("Vinci")<<endl;
    cout<< a.count("series")<<endl;
    cout<<c.postorder("series")<<endl;
    cout<< c.preorder("Complete") <<endl;
    b.order();
  }
  else // Prints error message in case  of failure while openning file!
  {
    printf("File  Error!");
  }

}