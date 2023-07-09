#include <bits/stdc++.h> 

void solve(vector<int> &nums, vector<int>&ans, int index, int sum)
{
    int n = nums.size();

    if(index == n)
    {
        ans.push_back(sum);
        return;
    }

    //pick the current index;
    solve(nums,ans,index+1, sum+nums[index]);
     //Dont pick the element
    solve(nums,ans,index+1, sum);

}
vector<int> subsetSum(vector<int> &nums)
{
    vector<int>ans;

    solve(nums,ans,0,0);
    sort(ans.begin(), ans.end());

    return ans;
}