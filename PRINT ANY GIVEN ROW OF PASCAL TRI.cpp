#include<iostream>
using namespace std;
int main(){
	cout<<"enter nth row";
	int n;
	cin>>n;
	int ans=1;
	cout<<ans<<endl;
	for(int i=1;i<n;i++){
		ans=ans*(n-i);
		ans=ans/(i);
		cout<<ans<<endl;
}
	
	
}
