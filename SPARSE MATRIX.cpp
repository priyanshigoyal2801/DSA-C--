#include<iostream>
using namespace std;
void sparsematrix(int &m,int &n,int &ctr, int trip[][3]){
	
	cout<<"enter no. of rows";
	cin>>m;
	cout<<"enter no. of columns";
	cin>>n;
	ctr=0;
	int sparse[m][n];
	cout<<"enter elements of sparse matrix";
	for(int i=0;i<m;i++){
		for(int j=0; j<n;j++){
			cin>>sparse[i][j];
			if(sparse[i][j]!=0){
			
			trip[++ctr][0]=i;
			trip[ctr][1]=j;
			trip[ctr][2]=sparse[i][j];
		}
		}
	}
	trip[0][0]=m;
	trip[0][1]=n;
	trip[0][2]=ctr;
}
void displaymatrix(int trip[][3], int ctr){
	for(int i=0;i<=ctr;i++){
		for(int j=0;j<3;j++){
			cout<<trip[i][j]<<" ";
		}
		cout<<endl;
	}
}
void transposematrix(int trip[][3],int trans[][3], int ctr){
	int m=trip[0][0];
	int n=trip[0][1];
	int total[n]={0};
	int index[n]={0};
	for(int i=1;i<=ctr;i++){
		total[trip[i][1]]++;
	}
	index[0]=1;
	for(int i=1;i<n;i++){
		index[i]=index[i-1]+total[i-1];
	}
	for(int i=1;i<=ctr;i++){
	
	int pos=index[trip[i][1]]++;
	trans[pos][0]=trip[i][1];
	trans[pos][1]=trip[i][0];
	trans[pos][2]=trip[i][2];
}
trans[0][0]=n;
trans[0][1]=m;
trans[0][2]=ctr;
displaymatrix(trans,ctr);
}
void addition(int trip1[][3],int ctr1,int trip2[][3],int ctr2,int add[][3]){
	int i=1,j=1,k=1;
	while(i<= ctr1 && j<=ctr2){
		if(trip1[i][0]< trip2[j][0]||(trip1[i][0]==trip2[j][0] && trip1[i][1]<trip2[j][1])){
			add[k][0]=trip1[i][0];
			add[k][1]=trip1[i][1];
			add[k][2]=trip1[i][2];
			i++;
		}else if(trip1[i][0]> trip2[j][0]||(trip1[i][0]==trip2[j][0] && trip1[i][1]>trip2[j][1])){
			add[k][0]=trip2[j][0];
			add[k][1]=trip2[j][1];
			add[k][2]=trip2[j][2];
			j++;
		}
		else {
			add[k][0]=trip1[i][0];
			add[k][1]=trip1[i][1];
			add[k][2]=trip1[i][2]+trip2[j][2];
			i++;
			j++;
		}
		k++;
	}
	while(i<=ctr1){
		add[k][0]=trip1[i][0];
			add[k][1]=trip1[i][1];
			add[k][2]=trip1[i][2];
			i++;
			k++;
	}
	while(j<=ctr2){
			add[k][0]=trip2[j][0];
			add[k][1]=trip2[j][1];
			add[k][2]=trip2[j][2];
			j++;
			k++;
	}
	add[0][0]=trip1[0][0];
	add[0][1]=trip1[0][1];
	add[0][2]=k-1;
	
	displaymatrix(add,add[0][2]);
	
}
int main(){
	int m1,n1,ctr1,m2,n2,ctr2;
	int trip1[100][3];
	int trip2[100][3];
	sparsematrix(m1,n1,ctr1,trip1);
	cout<<"triplet representation of matrix 1 is";
	displaymatrix(trip1,ctr1);
	cout<<endl;
	sparsematrix(m2,n2,ctr2,trip2);
	cout<<"triplet representation of matrix 2 is";
	displaymatrix(trip2,ctr2);
	cout<<endl;
	int trans1[ctr1+1][3];
	cout<<"transpose of matrix 1 is";
	transposematrix(trip1,trans1,ctr1);
	cout<<"addition of two sparse matrix is";
	if(m1==m2 && n1==n2){
		int add[ctr1+ctr2+1][3];
		addition(trip1,ctr1,trip2,ctr2,add);
		
	}
	else{
		cout<<"wrong input";
	}
	
	
}
