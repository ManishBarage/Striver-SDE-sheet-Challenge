#include <bits/stdc++.h> 

void solve(int index, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans)
{
    ans.push_back(ds);

    for(int i=index;i<arr.size();i++)
    {
        if(i != index and arr[i] == arr[i-1] )
        {
            continue;
        }

        ds.push_back(arr[i]);
        solve(i+1, arr,ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>>ans;
    vector<int>ds;

    sort(arr.begin(), arr.end());

    solve(0, arr, ds, ans);
    return ans;
}