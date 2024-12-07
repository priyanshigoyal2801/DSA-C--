#include <iostream>
#include <set>
using namespace std;

bool checkSum(int n , int x , int arr[]){
    int i;
    set<int> st;
    for(i = 0;i < n;i++){
        if(st.empty()){
            st.insert(arr[i]);
        }
        else{
            int k = x - arr[i];
            if(st.find(k) != st.end()){
                return true;
            }
            else{
                st.insert(arr[i]);
            } 
        }
    }
    return false;
}

int main(){
    int n , i , x;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(i = 0;i < n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the sum to be checked: ";
    cin>>x;

    bool val = checkSum(n , x , arr);
    if(val){
        cout<<"There exist elements whose sum is exactly equal to "<<x;
    }
    else{
        cout<<"There doesn't exist elements whose sum is exactly equal to "<<x;
    }

    return 0;
}