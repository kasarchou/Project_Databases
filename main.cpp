// Libraries we used
#include <iostream>
#include <chrono>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstring>
#include "Array.h"
#include "Ordered_Array.h"
#include "B_tree.h"
#include "AVL_tree.h"
#include "Hashtable.h"
//............................................MAIN................................................
int main() {
  using namespace std;
  string filename,word;
  int res,coum=0;
  srand(time(NULL));
  string search_vals[1000];
  int array_count[1000],ord_count[1000],bin_tree_count[1000],avl_count[1000],hash_count[1000];
  // Declare  our databases
  Array a;
  Ordered_Array b;
  B_tree c;
  AVL_tree d;
  Hashtable e;
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
      e.insert(word);
    }
    for(int i =0;i<1000;i++)
    {
      int random = rand() % a.getSize();
      search_vals[i] = a.getData(i);
    }
    b.order();
    auto start1 = chrono::steady_clock::now();
    for(int i =0;i<1000;i++)
    {
      array_count[i] = a.count(search_vals[i]);
    }
    auto end1 = chrono::steady_clock::now();
      chrono::duration<double>  elapse_seconds_a = end1 -  start1;
    auto start = chrono::steady_clock::now();
    for(int i =0;i<1000;i++)
    {
      ord_count[i]= b.count(search_vals[i]);
    }
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_b = end- start;
    start = chrono::steady_clock::now();
    for(int i =0;i<1000;i++)
    {
      bin_tree_count[i]= c.postorder(search_vals[i]);
    }
    end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_c = end - start;
    start = chrono::steady_clock::now();
    for(int i =0;i<1000;i++)
    {
      avl_count[i]= d.getCount(search_vals[i]);
    }
    end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_d = end -start;
    start = chrono::steady_clock::now();
    for(int i =0;i<1000;i++)
    {
      hash_count[i]= e.count(search_vals[i]);
    }
    end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_e = end - start;
    cout<<"Word   Array    Ordered_Array    Binary Tree    AVL Tree    Hashtable"<<endl<<endl;
    for(int i=0;i<1000;i++)
    {
      cout<<i+1<<")  "<<search_vals[i]<<": \t"<<array_count[i]<<" \t "<<ord_count[i]<<" \t "<<bin_tree_count[i]<<" \t "<<avl_count[i]<<" \t  "<<hash_count[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Times taken for count operations: "<<endl;
    cout<<"Array: "<<elapse_seconds_a.count()<<" seconds"<<endl;
    cout<<"Ordered Array: "<<elapsed_b.count()<<" seconds"<<endl;
    cout<<"Binary Tree: "<<elapsed_c.count()<<" seconds"<<endl;
    cout<<"Avl Tree: "<<elapsed_d.count()<<"seconds"<<endl;
    cout<<"Hashtable: "<<elapsed_e.count()<<" seconds"<<endl;


  }
  else // Prints error message in case  of failure while openning file!
  {
    printf("File  Error!");
  }

}