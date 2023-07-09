#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	unordered_map<int,int>mp;

	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	int dupli;
	int mis;
	for(int i=0;i<n;i++)
	{
		if(mp[arr[i]] > 1)
		{
			dupli = arr[i];
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(mp.find(i) == mp.end())
		{
			mis = i;
		}
	}

	return {mis,dupli};
	
}
