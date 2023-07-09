#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    if(root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode< int > *>q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        BinaryTreeNode< int > *rightNode = NULL;

        for(int i= size-1; i>=0;i--)
        {
            BinaryTreeNode< int > *curr = q.front();
            q.pop();

            curr->next = rightNode;
            rightNode = curr;

            if(curr->right != NULL)
            {
                q.push(curr->right);
            }

            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
        }
    }
}