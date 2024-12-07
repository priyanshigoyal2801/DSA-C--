#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> reverse(vector<int> &arr, int n){
	int temp[n/2];
	for(int i=0;i<n/2;i++){
		temp[i]=arr[i];
		arr[i]=arr[n-i-1];
		arr[n-i-1]=temp[i];
	}
	return arr;
}
int main(){
	int arr[]={1,2,3,4,45,6};
	int n=arr.size(arr)/arr.size(arr[0]);
	vector<int> result=reverse(&arr,n);
	for(int i=0;i<arr.size();i++){
		cout<<result[i]<<endl;
	}
}
