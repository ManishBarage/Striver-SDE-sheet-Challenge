#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int findPosition(vector<int> &inorder, int element , int n)
{
    for(int i=0;i<n;i++)
    {
        if(inorder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderStart, int inorderEnd, int n)
{
    //Base Case
    if(index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }
    
    int element = preorder[index++];
    TreeNode<int> *root = new TreeNode<int>(element);
    int position = findPosition(inorder, element,n);
    
    root->left = solve(inorder,preorder,index,inorderStart, position-1,n);
    root->right = solve(inorder,preorder,index,position+1,inorderEnd,n);
    
    return root;
    
    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int preOrderIndex =0;
    int n= inorder.size();
    TreeNode<int> *ans = solve(inorder,preorder,preOrderIndex,0,n-1,n);
    return ans;
}