#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cout<<"enter string";
	getline(cin,s);
	int n=s.length();
	for(int i=0; i<n/2; i++){
		char temp=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=temp;
	}
	cout<<s;
}
