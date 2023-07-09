#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int coins[9]={1,2,5,10,20,50,100,500,1000};

    int count =0;
    for(int i=8;i>=0;i--)
    {
       while(amount >=coins[i])
       {
           count++;
           amount-=coins[i];

       }
    }

    return count;
}
