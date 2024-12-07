#include <iostream>
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
    
    
    for(int i = 0; i < sz; i++)
    {
        for (int j=i+1; j<sz;j++)
        {
            if(arr[i] > arr[j])
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
