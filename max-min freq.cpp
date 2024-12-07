#include<iostream>
#include<bits/stdc++.h>
#include <map>
using namespace std;
void frequency(int arr[],int n){
	unordered_map <int,int> map;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}
	int count=0;
	for(auto it :mpp){
		if(count>it.second)
		count=it.second;
	}
	cout<<"max freq is"<<count;
}
int main(){
	int arr[5]={1,2,2,3,4};
	int n=(sizeof(arr)/sizeof(arr[0]));
	frequency(arr,n);
}
