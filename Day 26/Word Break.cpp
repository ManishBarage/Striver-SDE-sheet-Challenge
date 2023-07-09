#include <bits/stdc++.h> 
bool solve(int index,string &s,unordered_set<string>&st,vector<int>&dp)
{
    if(index == s.size())
    {
        return true;
    }
    string temp="";

    if(dp[index] !=-1)
    {
        return dp[index];
    }

    for(int j=index;j<s.size();j++)
    {
        temp+=s[j];
        if(st.find(temp) != st.end())
        {
            if(solve(j+1,s, st,dp))
            {
                return dp[index] = true;
            }
        }
    }
    return dp[index]=false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    
    unordered_set<string>st;
    vector<int>dp(target.size(),-1);

    for(auto a : arr)
    {
        st.insert(a);
    }

    return solve(0,target,st,dp);
}