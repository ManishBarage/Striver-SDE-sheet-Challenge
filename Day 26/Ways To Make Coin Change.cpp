#include<bits/stdc++.h>
long solve(int index, int *coins, int amount,vector<vector<long>>&dp)
    {
        if(index==0)
        {
            return (amount %coins[0]==0);
        }

        if(dp[index][amount]!=-1)
        {
            return dp[index][amount];
        }

        long notTake = solve(index-1,coins,amount,dp);

        long take =0;
        if(amount >= coins[index])
        {
            take = solve(index,coins,amount-coins[index],dp);
        }

        return dp[index][amount]= notTake + take;
    }
long countWaysToMakeChange(int *coins, int n, int amount)
{
    vector<vector<long>>dp(n, vector<long>(amount+1,-1));
    return solve(n-1,coins,amount,dp);
}