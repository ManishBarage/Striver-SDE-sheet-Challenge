void solve(int index, vector<int>arr, int target, vector<int>&ds, vector<vector<int>>&ans)
{
    if(index == arr.size())
    {
        if(target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

        ds.push_back(arr[index]);
        solve(index+1,arr, target-arr[index], ds, ans);
        ds.pop_back();
        solve(index+1,arr, target, ds, ans);


   
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
     vector<vector<int>>ans;
     vector<int>ds;

     solve(0, arr,k, ds, ans);
     return ans;
}