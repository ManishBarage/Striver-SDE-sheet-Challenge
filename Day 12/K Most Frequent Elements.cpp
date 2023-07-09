#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int>ans;
    priority_queue<pair<int,int>>pq;
    map<int,int>mp;

    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto i:mp)
    {
        pq.push(make_pair(i.second, i.first));
    }

    for (int i = 0; i < k; i++) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}