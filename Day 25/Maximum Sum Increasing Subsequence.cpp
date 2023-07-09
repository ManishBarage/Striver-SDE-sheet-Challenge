#include <bits/stdc++.h> 
int solve(int index, int prev, vector<int>&arr, int n , vector<vector<int>>&dp)
{
	if(index ==n)
	{
		return 0;
	}

	if(dp[index][prev+1]!= -1)
	{
		return dp[index][prev+1];
	}

	int len = solve(index+1,prev,arr,n,dp);

	if(prev==-1 || arr[prev] < arr[index])
	{
		len = max(len, arr[index]+solve(index+1,index,arr,n,dp));
	}
	return dp[index][prev+1] = len;
}
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, -1));
	return solve(0, -1,arr,n,dp);
}