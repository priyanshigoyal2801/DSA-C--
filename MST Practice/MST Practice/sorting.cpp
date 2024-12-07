//Bubble Sort
// #include <iostream>
// using namespace std;
// int main(){
//     int size=5;
//     int arr[size]={8,1,9,5,6};
//     for(int i=0;i<size-1;i++){
//         for(int j=0;j<size-i-1;j++){
//             if(arr[j]>arr[j+1]){    //< for descending
//                 swap(arr[j],arr[j+1]);
//             }
//         }
//     }
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//Selection Sort
// #include <iostream>
// using namespace std;
// int main(){
//     int size=6;
//     int arr[size]={13,46,24,52,20,8};
//     int i=0;
//     while(i<size-1){
//         int min=i;
//         for(int j=i;j<size;j++){
//             if(arr[j]<arr[min]){
//                 min=j;
//             }
//         }
//         swap(arr[i],arr[min]);
//         i++;
//     }
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//Insertion Sort
// #include <iostream>
// using namespace std;
// int main(){
//     int size=5;
//     int arr[size]={12,5,1,7,10};
//     for(int i=0;i<size;i++){
//         int j=i;
//         while(j>0 && arr[j-1]>arr[j]){
//             swap(arr[j-1],arr[j]);
//             j--;
//         }
//     }
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//Selection Sort Modified
// #include <iostream>
// using namespace std;
// int main(){
//     int size=6;
//     int arr[size]={13,46,24,52,20,8};
//     for(int i=0;i<size/2;i++){
//         int min=i;
//         int max=i;
//         for(int j=i;j<size-i;j++){
//             if(arr[j]<arr[min]){
//                 min=j;
//             }
//             if(arr[j]>arr[max]){
//                 max=j;
//             }
//         }
//         swap(arr[i],arr[min]);
//         if(max==i){
//             max=min;
//         }
//         swap(arr[size-i-1],arr[max]);
//     }
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//Binary Iterative Method
// #include <iostream>
// using namespace std;
// int main(){
//     int size=7;
//     int arr[size]={2,5,7,11,15,18,21,30};
//     int low=0,high=size-1,mid;
//     int target=15;
//     bool found=false;
//     while(low<=high){
//         mid=(low+high)/2;
//         if(target==arr[mid]){
//             cout<<"Element Found At Index: "<<mid<<endl;
//             found=true;
//             break;
//         }
//         else if(target>arr[mid]){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     if(!found){
//         cout<<"Target not in Array"<<endl;
//     }
//     return 0;
// }

//Binary Reccursive Method
// #include <iostream>
// using namespace std;
// int binary(int arr[],int target,int low,int high){
//     int mid;
//     if(low<=high){
//         mid=(low+high)/2;
//         if(target==arr[mid]){
//             return mid;
//         }
//         else if(target>arr[mid]){
//             binary(arr,target,mid+1,high);
//         }
//         else{
//             binary(arr,target,low,mid-1);
//         }
//     }
//     else{
//         return -1;
//     }
// }
// int main(){
//     int size=7;
//     int arr[size]={2,5,7,11,18,21,30};
//     int target=15;
//     cout<<binary(arr,target,0,size-1)<<endl;
//     return 0;
// }

