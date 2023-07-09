#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	int ans = arr[0];
	int maxi =ans;
	int mini =ans;

	for(int i=1;i<n;i++)
	{
		if(arr[i]<0)
		{
			swap(maxi,mini);
		}

		maxi = max(arr[i], maxi*arr[i]);
		mini = min(arr[i], mini*arr[i]);
		ans = max(ans, maxi);
	}

	return ans;
}
