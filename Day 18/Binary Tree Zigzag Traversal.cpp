#include <bits/stdc++.h> 
#include<queue>
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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> result;
    if(root ==  NULL)
    {
        return result;
    }
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool leftToRight = true;
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        
        for(int i=0;i<size;i++)
        {
            BinaryTreeNode<int>* frontNode = q.front();
            q.pop();
            
            int index = leftToRight ? i : size-i-1;
            ans[index] = frontNode -> data;
            
            if(frontNode->left != NULL)
            {
                q.push(frontNode -> left);
            }
            
            if(frontNode -> right != NULL)
            {
                q.push(frontNode -> right);
            }
        }
        
        //Change Direction
         leftToRight = !leftToRight;
        
        for(auto i : ans)
            result.push_back(i);
    }
    return result;
    
}
