#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int>st;
    st.push(-1);
    vector<int> ans(n,-1);
    
    for(int i=n-1;i>=0;i--)
    {
        int curr = arr[i];
        //pop until curr is less than small
        while(!st.empty() && st.top() <= curr)
        {
            st.pop();
        }
        
        if(i < n)
        {
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(curr);
        }
        
    }
    return ans;

}