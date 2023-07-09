#include<bits/stdc++.h>

int solve(int index1, int index2, string s, string t, vector<vector<int>>&dp)
{
	if(index1< 0 || index2<0)
	{
		return 0;
	}

	if(dp[index1][index2] !=-1)
	{
		return dp[index1][index2];
	}

	if(s[index1]==t[index2])
	{
		return dp[index1][index2] = 1+solve(index1-1,index2-1,s,t,dp);
	}

	return dp[index1][index2]= max(solve(index1-1,index2,s,t,dp), solve(index1, index2-1, s,t,dp));
}
int lcs(string s, string t)
{
	int n = s.size();
	int m = t.size();

	vector<vector<int>>dp(n, vector<int>(m, -1));
	return solve(n-1,m-1,s,t,dp);
}