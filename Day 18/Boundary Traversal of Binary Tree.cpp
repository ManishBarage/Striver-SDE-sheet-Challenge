#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
void traverseLeft(TreeNode<int>* root , vector<int> &ans)
{
    if((root == NULL) || root->left == NULL && root->right == NULL)
    {
        return;
    }
    
    ans.push_back(root->data);
    
    if(root->left != NULL)
    {
        traverseLeft(root->left,ans);
    }
    else
    {
        traverseLeft(root->right,ans);
    }
}

void traverseLeaf(TreeNode<int>* root , vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    
}

void traverseRight(TreeNode<int>* root, vector<int> &ans)
{
    if((root == NULL) || root->left == NULL && root->right == NULL)
    {
        return;
    }
    
    if(root->right != NULL)
    {
        traverseRight(root->right,ans);
    }
    else
    {
        traverseRight(root->left,ans);
    }
    
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    
    if(root == NULL)
    {
        return ans;
    }
    
    ans.push_back(root-> data);
    
    //Traverse Left part
    traverseLeft(root->left,ans);
    
    //Traverse leaf
    //Left Subtree
    traverseLeaf(root->left,ans);
    //Right Subtree
    traverseLeaf(root->right,ans);
    
    //Traverse right part
    traverseRight(root->right,ans);
    
    return ans; 
    
    
}