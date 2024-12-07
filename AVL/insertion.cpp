#include <iostream>
using namespace std;
class node
{
public:
    int data, height;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};
int getheight(node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int getbalance(node *root)
{
    return getheight(root->left) - getheight(root->right);
}
node *leftRotation(node *root)
{
    node *child = root->right;
    node *childleft = child->left;
    child->left = root;
    root->right = childleft;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}
node *rightRotation(node *root)
{
    node *child = root->left;
    node *childright = child->right;
    child->right = root;
    root->left = childright;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    return child;
}

node *insert(node *root, int key)
{
    if (!root)
        return new node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));

    // balancing check
    int balance = getbalance(root);

    // left left case
    if (balance > 1 && key < root->left->data)
    {
        return rightRotation(root);
    }
    // left right case
    else if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right right
    else if (balance < -1 && key > root->right->data)
    {
        return leftRotation(root);
    }
    // right left
    else if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    else
        return root;
}
void inorder(node* root){
    if(!root)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);
    cout<<"inorder";
    inorder(root);
}
