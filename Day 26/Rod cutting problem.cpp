int solve(int index, int size,vector<int>&price,vector<vector<int>>&dp)
{
	if(index == 0)
	{
		return size*price[0];
	}

	if(dp[index][size]!=-1)
	{
		return dp[index][size];
	}

	int nottake = solve(index-1, size, price,dp);

	int take =INT_MIN;
	if(index+1 <= size)
	{
		take = price[index] + solve(index,size-(index+1), price,dp);
	}

	return dp[index][size] = max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1,-1));
	return solve(n-1,n,price,dp);
}
