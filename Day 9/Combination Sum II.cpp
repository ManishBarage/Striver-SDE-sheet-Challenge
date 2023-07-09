#include <bits/stdc++.h> 

void solve(int index, int target, int sum,vector<int> &arr, int n,vector<int> &temp, vector<vector<int>> &ans)
{
    if(sum == target)
    {
        ans.push_back(temp);
        return;
    }
    
    if(sum > target)
    {
        return;
    }
    
    if(index == n)
    {
        return;
    }
    
    
    for(int i=index; i<n;i++)
    {
        sum +=arr[i];
        temp.push_back(arr[i]);
        solve(i+1,target, sum, arr,n,temp,ans);
        
        while(i < n && arr[i] == arr[i+1])
        {
            i++;
        }
        
        sum -= arr[i];
        temp.pop_back();
    }
    
    return;
    
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<int> temp;
    vector<vector<int>> ans;
    int index=0;
    int sum=0;
    
    sort(arr.begin(), arr.end());
    
    solve(index, target, sum, arr, n, temp, ans);
    return ans;
    
}
