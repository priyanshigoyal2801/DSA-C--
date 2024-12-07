#include <iostream>
#include <map>
using namespace std;

int maximumFreqElement(int n , int arr[]){
    int i , el = 0 , max = 0;
    map<int , int> hashmpp;
    for(i = 0;i < n;i++){
        hashmpp[arr[i]]++;
    }
    for(i = 0;i < n;i++){
        if(hashmpp[arr[i]] > max){
            max = hashmpp[arr[i]];
            el = arr[i];
        }
    }
    return el;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" array elements: ";
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int el = maximumFreqElement(n , arr);
    cout<<"Array Element with maximum frequency is: "<<el;

    return 0;
}