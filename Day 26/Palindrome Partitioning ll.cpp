#include <bits/stdc++.h> 
bool isPalindrome(string &temp)
{
    int s =0;
    int e = temp.size()-1;

    while(s<=e)
    {
        if(temp[s]==temp[e])
        {
            s++;
            e--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int solve(int i, string &str,vector<int>&dp)
{
    if(i==str.size())
    {
        return 0;
    }

    if(dp[i] != -1)
    {
        return dp[i];
    }

    string temp ="";
    
    
    int ans =INT_MAX;
    for(int j=i;j<str.size();j++)
    {
        temp+=str[j];

        if(isPalindrome(temp))
        {
            int cost = 1+solve(j+1,str,dp);
            ans = min(ans,cost);
        }

        
    }

    return dp[i]=ans;
}
int palindromePartitioning(string str) {
    vector<int>dp(str.size(), -1);
    
    return solve(0, str,dp)-1;
}
