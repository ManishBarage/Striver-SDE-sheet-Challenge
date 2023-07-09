#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    vector<int>nums;
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            nums.push_back(matrix[i][j]);
        }
    }

    int size = nums.size();
    sort(nums.begin(), nums.end());

    return nums[size/2];
}