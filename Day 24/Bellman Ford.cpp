#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {

    vector<int>dis(n+1, 1e9);

    dis[src]=0;

    //Check for n-1 time
    for(int i=1;i<=n;i++)
    {
        //traverse over edge list
        for(int j=0;j<m;j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dis[u] != 1e9 && (dis[u]+w < dis[v]))
            {
                dis[v]=dis[u]+w;
            }
        }
    }
    

    //check for negative cycle
    bool flag =false;
    for(int j=0;j<m;j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dis[u] != 1e9 && (dis[u]+w < dis[v]))
        {
            flag = true;
        }
    }

    if(flag == true)
    {
        return -1;
    }

    return dis[dest];
    

}