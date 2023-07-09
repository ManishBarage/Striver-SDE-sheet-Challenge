#include <bits/stdc++.h> 
int solve(int i, int j, vector<int>&arr,vector<vector<int>>&dp)
{
    if(i==j)
    {
        return 0;
    }

    if(dp[i][j]!= -1)
    {
        return dp[i][j];
    }

    int mini = INT_MAX;

    for(int k=i;k<j;k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp)+solve(k+1,j,arr,dp);

        if(steps < mini)
        {
            mini = steps;
        }
    }
    return dp[i][j]= mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N, vector<int>(N, -1));
    return solve(1, N-1, arr,dp);
}