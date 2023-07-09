vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	int m = arr.size();
	int n = queries.size();

	vector<int>ans(n,-1);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[j] <= queries[i][1])
			{
				ans[i] = max(ans[i], arr[j]^queries[i][0]);
			}
		}
	}

	return ans;
}