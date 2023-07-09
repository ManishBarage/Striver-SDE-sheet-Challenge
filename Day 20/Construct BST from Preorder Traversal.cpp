#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(int &index,vector<int> &preOrder,int mini, int maxi)
{
    if(index >= preOrder.size())
    {
        return NULL;
    }

    if(preOrder[index] < mini || preOrder[index] >maxi)
    {
        return NULL;
    }

    TreeNode<int>* root = new TreeNode<int>(preOrder[index++]);
    root->left = solve(index,preOrder,mini, root->data);
    root->right= solve(index,preOrder,root->data, maxi);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index =0;
    return solve(index, preOrder, mini, maxi);
}