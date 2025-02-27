#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class Solution{
public:
prevSmaller(vector<int>A);
};
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> sol(A.size(), -1);
    stack<int> st;
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        sol[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    return sol;
}
