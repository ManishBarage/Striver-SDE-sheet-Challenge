#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder(vector<int> &ans, TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(ans, root->left);
    ans.push_back(root->data);
    inorder(ans, root->right);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    inorder(ans, root);
    return ans;
}