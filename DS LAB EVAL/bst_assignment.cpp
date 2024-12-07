#include<iostream>
#include <climits>
// #include<bits/stdc++.h>
#include<stack>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    
};
void preOrder(TreeNode* root){
        if(root==NULL)
        return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrder(TreeNode* root){
        if(root==NULL)
        return;
        
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    void postOrder(TreeNode* root){
        if(root==NULL)
        return;
        
        postOrder(root->left);
        postOrder(root->right);
         cout<<root->data<<" ";
    }

bool search(TreeNode* root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            cout << "Element found: " << key << endl;
            return true;
        } else if (key > root->data) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    cout << "Element not found: " << key << endl;
    return false;
}

// bool search(TreeNode* root, int key){
//     if(root==NULL){
// cout<<"element not found";
//     return false;
//     }
    
//         if(key==root->data){
//             cout<<"element found";
//             return true;
//         }
//         else if(key>root->data)
//         return search(root->right,key);
//         else
//         return search(root->left,key);
    
    
// }
void max_element(TreeNode* root){
        if(root==NULL)
    return;
    while(root->right!=NULL){
root=root->right;
    }
    cout<<"max element is " << root->data;
}
int min_element(TreeNode* root){
        if(root==NULL)
    return -1;
    while(root->left!=NULL){
root=root->left;
    }
    return root->data;
}

int inorderSucc(TreeNode* root,int val){
    TreeNode* succ=NULL;
    if(root==NULL)
    return -1;
    
    while(root!=NULL){
        if(val>=root->data){
            root=root->right;
        }else{
            succ=root;
            root=root->left;
        }
    }
    return succ->data;
}
int inorderPred(TreeNode* root, int val) {
    TreeNode* pred = NULL;

    while (root != NULL) {
        if (val > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return (pred != NULL) ? pred->data : -1;
}

bool isValid(TreeNode* root, int mini, int maxi){
    if(root==NULL)
    return true;
    if(root->data>=maxi||root->data<=mini)
    return false;
    return isValid(root->left,mini,root->data)&&isValid(root->right,root->data,maxi);
}
bool isValidBST(TreeNode* root){
    return isValid(root,INT_MIN,INT_MAX);
}
int maxDepth(TreeNode* root){
    if(root==NULL)
    return 0;
    int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return 1+max(left,right);

}
int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;

    // If one of the subtrees is NULL, only consider the other subtree
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);

    // If both subtrees exist, take the minimum depth of both
    return 1 + min(minDepth(root->left), minDepth(root->right));
}
void inorderTraversal(TreeNode* root){
    if(root==NULL)
    return;
    stack<TreeNode* > st;
    TreeNode* node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()) break;
         node=st.top();
        cout<<node->data<<" ";
        st.pop();
        node=node->right;
        }
    }
}
void insertion(TreeNode* &root, int val){
    if(root==NULL){
        root=new TreeNode(val);
    }
    else{
     if(val>root->data){
        insertion(root->right,val);
    }
    else{
        insertion(root->left,val);
    }
    }
}
TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Replace with inorder successor
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    TreeNode* root= new TreeNode(7);
    root->left=new TreeNode(2);
        root->right=new TreeNode(8);

    root->left->right=new TreeNode(5);
    // preOrder(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // if(search(root,5)) cout<<"yes";
    // else cout<<"no";
    // cout<<endl;
    // max_element(root);
insertion(root,11);
insertion(root,6);
deleteNode(root,8);
    // int succ= inorderSucc(root,2);
    //  cout<<succ<<endl;
    // int pred=inorderPred(root,5);
    //  cout<<pred<<endl;
    // if(isValidBST(root))
    // cout<<"yes";
    // else cout<<"no";
    // int d=minDepth(root);
    // cout<<d;

    inorderTraversal(root);


}