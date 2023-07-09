#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if(i==0 && j==0)
    {
        return grid[i][j];
    }

    if(i<0 || j<0)
    {
        return 1e9;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int up = grid[i][j] + solve(i-1,j,grid,dp);
    int left = grid[i][j] + solve(i,j-1,grid,dp);

    return dp[i][j] = min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, -1));

    return solve(n-1,m-1,grid,dp);



    //Using Tabulation

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         if(i==0 && j==0)
    //         {
    //             dp[0][0] = grid[0][0];
    //         }
    //         else
    //         {
    //             int up = grid[i][j];
    //             if(i>0)
    //             {
    //                 up += dp[i-1][j];
    //             }
    //             else
    //             {
    //                 up+=1e9;
    //             }

    //             int left = grid[i][j];
    //             if(j>0)
    //             {
    //                 left +=dp[i][j-1];
    //             }
    //             else
    //             {
    //                 left +=1e9;
    //             }

    //             dp[i][j] = min(left,up);
    //         }
    //     }
    // }

    // return dp[n-1][m-1];
}