#include<bits/stdc++.h>
int solve(int index, int w,vector<int> &values, vector<int> &weights, vector<vector<int>>&dp)
{

	//Base case
	if(index ==0)
	{
		if(weights[0] <= w)
		{
			return values[0];
		}
		else
		{
			return 0;
		}
	}

	if(dp[index][w]!=-1)
	{
		return dp[index][w];
	}

	//Not take the curret element ans move backward
	int notTake = solve(index-1, w, values,weights,dp);

	int take =INT_MIN;
	//Take current element and move backward
	if(weights[index] <= w)
	{
		take =values[index] + solve(index-1, w-weights[index], values, weights,dp);
	}

	return dp[index][w]= max(notTake, take);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{

	vector<vector<int>>dp(n, vector<int>(w+1,-1));
	return solve(n-1, w, values, weights,dp);
}