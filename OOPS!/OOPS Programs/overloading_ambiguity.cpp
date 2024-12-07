//  #include <iostream> 
// using namespace std; 
// //float myfunc(float i); 
// double myfunc(double i);
//  int main()
//  {
//  cout << myfunc(10.1) << " "; // unambiguous, calls myfunc(double)
//  cout << myfunc('c'); // ambiguous return 0;
//  }
#include<iostream>
 using namespace std;
 template <class T, int size> 
void show(T a){cout<<a<<", "<<size;}
 int main(){
 show <char,10> ('c');
 }
