#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int solve(TreeNode<int> *root, long long int &maxi)
{
    if(root == NULL)
    {
        return 0;
    }

    long long int left = solve(root->left, maxi);
    long long int right = solve(root->right, maxi);

    maxi = max(maxi, root->val+left+right);

    return root->val + max(left, right);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
   if(root==NULL || root->left==NULL || root->right == NULL)
   {
       return -1;
   }

   long long int maxi =0;
   solve(root, maxi);
   return maxi;
}