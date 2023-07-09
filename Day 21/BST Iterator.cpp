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

class BSTiterator
{
    public:
    stack<TreeNode<int> *>st;

    BSTiterator(TreeNode<int> *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode<int> *temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
       if(st.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void pushAll(TreeNode<int> *root)
    {
        while(root != NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/