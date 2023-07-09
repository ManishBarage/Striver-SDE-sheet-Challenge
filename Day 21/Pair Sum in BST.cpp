#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void solve(BinaryTreeNode<int> *root, vector<int>&arr)
    {
        if(root == NULL)
        {
            return;
        }

        solve(root->left, arr);
        arr.push_back(root->data);
        solve(root->right, arr);
    }
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int>arr;
        solve(root,arr);

        int left = 0; int right = arr.size()-1;
        while(left < right)
        {
            int sum =arr[left]+arr[right];
            if(sum == k)
            {
                return true;
            }
            else if(sum <k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
         return false;
}