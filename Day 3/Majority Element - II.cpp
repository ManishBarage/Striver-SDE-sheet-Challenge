#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    vector<int>ans;
    unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
	}

	for(auto i:mp)
	{
		if(i.second > floor(n/3))
		{
			ans.push_back(i.first);
		}
	}
	return ans;
}