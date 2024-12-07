#include<iostream>
using namespace std;
int main(){
	int rows,columns;
	cout<<"enter rows and columns of matrix";
	cin>>rows>>columns;
	int matrix[rows][columns];
	for(int i=0;i<rows;i++){
		for(int j=0;j<columns;j++){
			cin>>matrix[i][j];
		}
	}
	for(int i=0; i<rows; i++){
		int rowsum=0;
		for(int j=0; j<columns ;j++){
			rowsum+=matrix[i][j];
		}
		cout<<"sum of row"<<i+1<<endl<<rowsum<<endl;
	}
	for(int j=0; j<columns; j++){
		int colsum=0;
		for(int i=0;i<rows;i++){
			colsum+=matrix[i][j];
		}
		cout<<"sum of cols"<<j+1<<endl<<colsum<<endl;
	}
}
