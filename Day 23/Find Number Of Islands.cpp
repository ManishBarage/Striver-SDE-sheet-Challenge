#include<bits/stdc++.h>

void bfs(int row, int col,vector<vector<int>>&vis,int** arr, int n, int m)
{
   vis[row][col]=1;

   queue<pair<int,int>>q;
   q.push({row,col});

   while(!q.empty())
   {
      int x = q.front().first;
      int y =q.front().second;
      q.pop();

      for(int drow=-1;drow<=1;drow++)
      {
         for(int dcol=-1;dcol<=1;dcol++)
         {
            int nrow = x +drow;
            int ncol = y+dcol;

            if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && !vis[nrow][ncol] && arr[nrow][ncol]==1)
            {
               q.push({nrow, ncol});
               vis[nrow][ncol]=1;
            }
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   vector<vector<int>>vis(n, vector<int>(m, 0));

   int count =0;

   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(!vis[i][j] && arr[i][j]==1)
         {
            count++;
            bfs(i,j,vis,arr,n,m);
         }
      }
   }

   return count;
}
