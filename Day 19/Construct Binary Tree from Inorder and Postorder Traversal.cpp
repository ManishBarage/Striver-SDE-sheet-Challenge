/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
int findPosition(vector<int>& inOrder, int element , int n)
{
    for(int i=0;i<n;i++)
    {
        if(inOrder[i] == element)
        {
            return i;
        }
    }
    return -1;
}

TreeNode<int>* solve(vector<int>& postOrder, vector<int>& inOrder,int &index, int inorderStart, int inorderEnd,int n)
{
    //Base Case
    if(index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }
    
    int element = postOrder[index--];
    TreeNode<int>* root = new TreeNode<int>(element);
    int position = findPosition(inOrder,element , n);
    
    root->right = solve(postOrder,inOrder,index,position+1,inorderEnd,n);
    root->left = solve(postOrder,inOrder,index,inorderStart,position-1,n);
    
    return root;
    
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    int n = postOrder.size();
	int postIndex = n-1;
    
    TreeNode<int>* ans = solve(postOrder,inOrder,postIndex,0,n-1,n);
    return ans;
    
}
