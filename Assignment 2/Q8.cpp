#include <iostream>
#include <set>
using namespace std;

int main()
{
    int sz;
   cout<<"Enter the size of array::";
   cin>>sz;
   int arr[sz];
   for(int i=0;i<sz;i++)
      arr[i]=rand()%10;  //Generate number between 0 to 99
    cout << "Array is: { ";
    for (int i=0;i<sz;i++){
        cout << arr[i]<<' ';
    }
    cout << "}" << endl;
    int cnt=0;
    set <int> myset;
//count the total number of distinct elements
    for (int i = 0; i < sz; i++)
    {
        myset.insert(arr[i]);
    }
    //OR

    // int distinctCount = 0;
    // for (int i = 0; i < n; i++) {
    //     bool isDistinct = true;
    //     for (int j = 0; j < i; j++) {
    //         if (arr[i] == arr[j]) {
    //             isDistinct = false;
    //             break;
    //         }
    //     }
    //     if (isDistinct) {
    //         distinctCount++;
    //     }
    // }
    // cout << "Number of distinct elements in array is: "<<myset.size()<<endl;
    
    cout << myset.size();
    return 0;
}