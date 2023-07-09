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
pair<int,int> diameterFast(TreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    
    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second;
    
    pair<int,int> ans;
    ans.first = max(opt1, max(opt2,opt3));
    ans.second = max(left.second , right.second) +1;
    
    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	return diameterFast(root).first;
}
