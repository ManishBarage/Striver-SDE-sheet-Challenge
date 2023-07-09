/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<stack>
int findCelebrity(int n) {
 	
    stack<int> st;
    
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }
        
        while(st.size() > 1)
        {
            int a = st.top();
            st.pop();
            
            int b= st.top();
            st.pop();
            
            if(knows(a,b))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        
        //here can be a potential celebrity
        int ans = st.top();
        
        //check celebrity conditions (verify celbrity)
        
        int zeroCount =0;
        
        for(int i =0;i<n;i++)
        {
            if(knows(ans,i))
            {
                return -1;
            }
            else
            {
                zeroCount++;
            }
        }
        
        if( zeroCount != n)
            return -1;
        
        int oneCount = 0;
        for(int i=0;i<n;i++)
        {
            if(knows(i,ans))
            {
                oneCount++;
            }
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
           
    
}