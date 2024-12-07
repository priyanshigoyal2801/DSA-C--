#include<iostream>
using namespace std;
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int el;
	cout<<"enter element to be searched";
	cin>>el;
	int n=sizeof(arr)/sizeof(arr[0]);
	int low=0;
	int high=n-1;
	int mid=(low+high)/2;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==el){
			cout<<"element found at index"<<mid;
			break;
			
		}
		else if(arr[mid]>el){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
}
