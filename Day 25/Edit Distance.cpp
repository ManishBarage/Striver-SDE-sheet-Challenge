#include<bits/stdc++.h>

int solve(int i, int j, string &s1, string &s2,vector<vector<int>>&dp)
{
    if(i<0)
    {
        return j+1;
    }

    if(j<0)
    {
        return i+1;
    }

    if(dp[i][j]!= -1)
    {
        return dp[i][j];
    }

    if(s1[i]==s2[j])
    {
        return dp[i][j]=solve(i-1,j-1, s1, s2,dp);
    }

    int insert = 1+solve(i, j-1, s1, s2,dp);
    int dele = 1+solve(i-1, j, s1, s2,dp);
    int repla = 1+solve(i-1, j-1, s1, s2,dp);

    return dp[i][j] = min(insert, min(dele, repla));
}

int editDistance(string str1, string str2)
{
   int n = str1.size();
   int m = str2.size();

   vector<vector<int>>dp(n, vector<int>(m, -1));

   return solve(n-1,m-1,str1, str2,dp);
}