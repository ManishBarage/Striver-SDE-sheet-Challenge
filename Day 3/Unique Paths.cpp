#include <bits/stdc++.h> 

int solve(int i, int j, int m, int n,vector<vector<int>>&dp)
{
	if(i==n-1 && j==m-1)
	{
		return 1;
	}
	if(i >=n || j >=m)
	{
		return 0;
	}
	 if(dp[i][j] !=-1)
	{
		return dp[i][j];
	}
	else
	{
		return dp[i][j] = solve(i+1, j, m,n,dp) + solve(i,j+1,m,n,dp);
	}
}
int uniquePaths(int m, int n) {
	vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
	
	int ans = solve(0,0,m,n,dp);
	if(m==1 && n==1)
	{
		return ans;
	} 

	return dp[0][0];
}