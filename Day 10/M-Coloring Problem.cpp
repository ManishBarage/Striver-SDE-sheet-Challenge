#include <bits/stdc++.h> 

bool isSafe(int node, int color[], vector<vector<int>> &mat, int n, int col)
{
    for(int k=0;k<n;k++)
    {
        if(k!= node && mat[k][node] ==1 && color[k] == col)
        {
            return false;
        }
    }

    return true;
}
bool solve(int node, int color[],vector<vector<int>> &mat,int n, int m)
{
    if(node == n)
    {
        return true;
    }

    for(int i=1;i<=m;i++)
    {
        if(isSafe(node, color, mat,n,i))
        {
            color[node]=i;

            if(solve(node+1, color, mat,n,m))
            {
                return true;
            }
            else
            {
                color[node]=0;
            }
        }
    }

    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat[0].size();
    int color[n]={0};

    if(solve(0,color, mat, n,m))
    {
       return "YES"; 
    }
    else
    {
        return "NO";
    }


    
}