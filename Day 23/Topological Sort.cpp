#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>ans;
    vector<int>adj[v];
    vector<int>indegree(v,0);

    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);

        indegree[v]++;
    }

    queue<int>q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto i:adj[node])
        {
            indegree[i]--;

            if(indegree[i] ==0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}
