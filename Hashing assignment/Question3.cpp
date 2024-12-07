#include <iostream>
#include <set>
#include <vector>
using namespace std;

void findDistinctNumbers(int n1 , int n2 , int arr1[] , int arr2[]){
    set<int> st;
    vector<int> ans;
    int i;
    for(i = 0;i < n2;i++){
        st.insert(arr2[i]);
    }
    for(i = 0;i < n1;i++){
        if(st.find(arr1[i]) == st.end()){
            ans.push_back(arr1[i]);
        }
    }
    cout<<"Array elements present in first array but not in second array are: ";
    if(ans.empty()){
        cout<<"NIL";
    }
    else{
        for(i = 0;i < ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
}

int main(){
    int n1 , n2 , i;
    cout<<"Enter size of first array: ";
    cin>>n1;
    int arr1[n1];
    cout<<"Enter "<<n1<<" array elements for first array: ";
    for(i = 0;i < n1;i++){
        cin>>arr1[i];
    }
    cout<<endl<<"Enter size of second array: ";
    cin>>n2;
    int arr2[n2];
    cout<<"Enter "<<n2<<" array elements for second array: ";
    for(i = 0;i < n2;i++){
        cin>>arr2[i];
    }
    findDistinctNumbers(n1 , n2 , arr1 , arr2);

    return 0;
}