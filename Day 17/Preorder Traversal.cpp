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
void preOrder(vector<int> &ans, TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->data);
    preOrder(ans, root->left);
    preOrder(ans, root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    preOrder(ans, root);
    return ans;
}