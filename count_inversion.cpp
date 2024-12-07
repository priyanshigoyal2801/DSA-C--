#include<iostream>
using namespace std;
int main(){
    int arr[]={5,3,2,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int cnt=0;
    for(int i=0;i<n-1;i++ ){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
}