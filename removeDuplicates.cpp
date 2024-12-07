#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[], int n){
	int i=0;
	for(int j=1;j<n;j++){
		if(arr[j]!=arr[i]){
			
			i++;
			arr[i]=arr[j];
		}
	}
	return i+1;
}

int main(){
	int arr[]={1,1,1,2,2,3,3,3,3,4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int index= removeDuplicates(arr,n);
	for(int i=0;i<index;i++){
		cout<<arr[i]<<endl;
	}
}
