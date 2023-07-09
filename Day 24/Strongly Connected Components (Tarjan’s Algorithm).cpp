#include<bits/stdc++.h>

void topoSort(int node , vector<int>&vis, stack<int>&st,unordered_map<int, list<int>>adj )
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            topoSort(i, vis, st, adj);
        }
    }
    st.push(node);
}

void dfs(int node,vector<int>&vis,vector<int>&temp, unordered_map<int, list<int>>transpose)
{
    vis[node]=1;
    temp.push_back(node);

    for(auto i:transpose[node])
    {
        if(!vis[i])
        {
            dfs(i, vis,temp,transpose);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>>adj;
    unordered_map<int, list<int>>transpose;

    for(auto i:edges)
    {
        int u = i[0];
        int v = i[1];

        adj[u].push_back(v);
        transpose[v].push_back(u);
    }

    //Step 1 : Topological Sort
    stack<int>st;
    vector<int>vis(n, 0);

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topoSort(i,vis,st,adj);
        }
    }

    fill(vis.begin(), vis.end(),0); //Marking all unvisited

    //DFS on transpose graph

    vector<vector<int>>ans;

    while(!st.empty())
    {
        vector<int>temp;
        int node = st.top();
        st.pop();

        if(!vis[node])
        {
            dfs(node,vis, temp,transpose);
        }

        ans.push_back(temp);
    }

    return ans;
}