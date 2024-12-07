#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[]={1,1,1,2,5,2,1,3,4,3};
	set<int> st;
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<n; i++){
		st.insert(arr[i]);
	}
	cout<<st.size();
//	int cnt=0;
//	for(auto it = st.begin(); it != st.end(); ++it){
//		cout<<*it;
//	}
//	cout<<"distinct elements are"<<cnt;
}
