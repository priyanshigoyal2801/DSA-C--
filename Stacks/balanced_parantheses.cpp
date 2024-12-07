#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
string s="({ { ][})";
stack<int>st;
for(int i=0;i<s.size();i++){
    if(s[i] == "("||"{"||"["){
        st.push(s[i]);
    }
    else{
        st.pop();
    }
}
if(st.empty()){
    cout<<"balanced";
}
else{
    cout<<"not balanced";
}
}