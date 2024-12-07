#include<iostream>
using namespace std;
void pattern3(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}
void pattern4(int n){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n-i+1;j++){
			cout<<"*";
		}
		cout<<endl;
	}
}
void pattern5(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cout<<j;
		}
		cout<<endl;
	}
}
void pattern6(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			cout<<" ";
		}
		for(int j=0;j<2*i+1;j++){
			cout<<"*";
		}
		for(int j=0;j<n-i-1;j++){
			cout<<" ";
		}
		cout<<endl;
	}
}
void pattern7(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			cout<<" ";
		}
		for(int j=0;j<2*n-(2*i+1);j++){
			cout<<"*";
		}
		for(int j=0;j<i;j++){
			cout<<" ";
		}
		cout<<endl;
	}
}
void pattern8(int n){
	for(int i=1;i<=2*n-1;i++){
		int stars = i;
		if(i>n){
			stars = 2*n-i;
		}
		for(int j=1;j<=stars;j++){
			cout<<"*";
		}
		cout<<endl;
	}
}
void pattern9(int n){
	int start=1;
	for(int i=0;i<n;i++){
		
		if(i%2==0){
			start = 1;
		}
		else start = 0;
	for(int j=0;j<=i;j++){
		cout<<start;
		start = 1-start;
	}
	cout<<endl;
}
}
void pattern10(int n){
	int space = 2*n-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<j;
		}for(int j=1;j<=space;j++){
			cout<<" ";
		}
		for(int j=i;j>=1;j--){
			cout<<j;
		}
		cout<<endl;
		space -= 2;
	}
}
void pattern11(int n){
	int num = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<num<<" ";
			num ++;
		}
		cout<<endl;
	}
}
void pattern12(int n){
	for(int i=0;i<n;i++){
		for(char ch='A';ch <='A'+i;ch++){
			cout<< ch <<" ";
		}
		cout<<endl;
		}
	}
void pattern13(int n){
	for(int i=1;i<=n;i++){
		for( char ch='A'; ch<= 'A'+ n-i; ch++){
			cout<< ch<< " ";
		}
		cout<<endl;
	}
}
void pattern14(int n){
	for(int i=1;i<=n;i++){
		char ch = 'A'+i -1;
		for(int j=1;j<=i;j++){
		cout<<ch<<" ";
		}
		cout<<endl;
	}
}
void pattern15(int n){
	char ch='A';
		for(int i=1;i<=n;i++){
		for(int j=1;j<= n-i ;j++){
			cout<<" ";
		}
		int breakpt= (2*i-1)/2 +1;
		for(int j=1;j<= 2*i-1; j++){
			cout<<ch;
			if(j<=breakpt){
				ch++;
			}else ch--;
		}
		for(int j=1;j<= n-i ;j++){
			cout<<" ";
		}
		cout<<endl;
	}
}
void pattern16(int n){
	for(int i=0;i<n;i++){
		for(char ch='E'-i; ch<='E';ch++){
			cout<<ch<<" ";
		}
		cout<<endl;
	}
}
void pattern17(int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			cout<<"*";
		}
		for(int j=0;j<(2*i);j++){
			cout<<" ";
		}
		for(int j=1;j<=n-i;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	int insp=8;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		for(int j=1;j<=insp;j++){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
		insp-=2;
	}
}
void pattern18(int n){
	int insp=8;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		for(int j=0;j<insp;j++){
			cout<<" ";
		}
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
		insp-=2;
	}
	int ins=2;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			cout<<"*";
		}
		for(int j=1;j<=ins;j++){
			cout<<" ";
		}
		for(int j=1;j<=n-i;j++){
			cout<<"*";
		}
		cout<<endl;
		ins+=2;
	}
}
void pattern19(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==1||i==n||j==1||j==n){
				cout<<"*";
			}
			else cout<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	pattern19(n);
}

