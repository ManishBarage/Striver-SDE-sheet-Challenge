#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, int &K, int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        solve(root->right, K, ans);
        K--;
        if(K==0)
        {
            ans = root->data;
            return;
        }
        
        solve(root->left, K, ans);
    }
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans =-1;
    solve(root, k, ans);
    return ans;
}
