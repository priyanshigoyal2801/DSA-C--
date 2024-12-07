#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void diagonal(int n, int m, int matrix[n ][m],int diag[]){
	for(int i=0; i<min(n,m);i++){
		
		diag[i]=matrix[i][i];
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==j)
			cout<<diag[i];
			else
			cout<<"0";
		}
		cout<<endl;
	}
	
}
void tridiagonal(int n, int m, int matrix[n][m],int tridiag[]){
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i-j==1){
				tridiag[k++]=matrix[i][j];
			}
			else if(i==j)
			tridiag[k++]=matrix[i][j];
			else if(i-j==-1)
			tridiag[k++]=matrix[i][j];
		}
	}
}
void lowertri(int n,int m, int matrix[n][m],int lower[]){
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i>=j){
				lowertri[k++]=matrix[i][j];
			}
		}
		}
}

void uppertri(int n,int m, int matrix[n][m],int upper[]){
	int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i<=j){
				uppertri[k++]=matrix[i][j];
				cout<<
			}
		}
		}
}


int main(){
	int n,m;
	cout<<"enter no. of rows";
	cin>>n;
	cout<<"enter no. of columns";
	cin>>m;
	cout<<"enter matrix elements";
	int matrix[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>matrix[n][m];
		}
	}
	int mini=min(n,m);
	int diag[mini];
	int tridiag[3*mini-2];
	int low= (n * (n + 1)) / 2;
    int lower[low];
    int up= (m * (m + 1)) / 2;
    int upper[up];
    
	cout<<"choose"<<"1. diagonal matrix"<<endl<<"2. tri diagonal"<<endl<<"3. lower triangle"<<endl<<"4.upper triangle"<<endl<<;
	int x;
	switch(x){
		case 1:
			diagonal(n,m,matrix,diag);
			break;
			case 2:
				tridiagonal(n,m,matrix,tridiag);
				break;
				case 3:
					lowertri(n,m,matrix,lower);
					break;
					case 4:
						uppertri(n,m,matrix,upper);
						break;
	}
	
}



