#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> * root, int X, int &ans)
{
    if(root==NULL)
    {
        return;
    }


    if(root->val == X)
    {
       ans =root->val;
    }

    if(root->val < X)
    {
        ans = root->val;
        solve(root->right,X,ans);
    }
    else if(root->val > X)
    {
        solve(root->left, X,ans);
    }

}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    solve(root, X,ans);
    return ans;

}