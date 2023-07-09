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
void inorder(BinaryTreeNode<int>* root, vector<int>&arr)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    
    vector<int>arr;
    inorder(root, arr);

    BinaryTreeNode<int>* dummy = new BinaryTreeNode<int>(-1);
    BinaryTreeNode<int>* head = dummy;

    for(int i=0;i<arr.size();i++)
    {
        BinaryTreeNode<int>* curr = new BinaryTreeNode<int>(arr[i]);

        curr->left = head;
        head->right = curr;
        head = curr;
    }

    head->right = NULL;

    return dummy->right;
}