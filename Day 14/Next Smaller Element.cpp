#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    st.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1;i>=0;i--)
    {
        int curr = arr[i];
        //pop until top is greater
        while(curr <= st.top()) 
        {
            st.pop();
        }
        
        //top is less than curr
        ans[i] = st.top(); //put top in answer
        st.push(curr);
    }
    return ans;
}