#include <iostream>
#include <vector>
#include "functor.h"
#include "msort.h"

using namespace std;

int main() {
  string s1 = "four";
  string s2 = "five";
  AlphaStrComp comp1;
  LengthStrComp comp2;
  NumStrComp comp3;

  // Here comp1(s1,s2) is calling comp1.operator() (s1, s2);
  cout << "four compared to five using AlphaStrComp yields " << comp1(s1, s2) << endl;

  // Here comp2(s1,s2) is calling comp2.operator() (s1, s2);
  cout << "4 compared to 5 using LenStrComp yields " << comp2(s1, s2) << endl;

  cout << "4 compared to 5 using NumStrComp yields " << comp3(s1,s2) << endl;

  vector<string> v1{"one", "two", "three", "four", "six"};
  vector<string> v2{"2", "1", "4", "3", "5"};

  mergeSort(v1, 2, comp3);

  for (unsigned int i = 0; i < v1.size(); ++i)
  {
    cout<<v1[i]<<endl;
  }
  cout<<endl;

  

  return 0;
}
