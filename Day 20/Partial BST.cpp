#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool isValid(BinaryTreeNode<int> *root, long mini, long maxi)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data <mini || root->data > maxi)
    {
        return false;
    }

    return (isValid(root->left, mini, root->data) && isValid(root->right, root->data, maxi));
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isValid(root, LONG_MIN, LONG_MAX);
}