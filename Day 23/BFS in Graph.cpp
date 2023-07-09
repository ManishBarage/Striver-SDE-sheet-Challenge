#include <bits/stdc++.h> 
void createAdjList(unordered_map<int, set<int> > &adj, vector<pair<int, int>> &edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int> > &adj, unordered_map<int, bool> &visited ,vector<int> &ans, int node )
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        //Store frontNode in ans
        ans.push_back(frontNode);
        
        //Travers all neighbours of frontNode
        for(auto i : adj[frontNode])
        {
            if(visited[i] == false)
            {
                q.push(i);
                visited[i] =true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int> > adj;
    unordered_map<int, bool> visited;
    vector<int> ans;
    
    createAdjList(adj, edges);
    
    //Traveres all compnents of graph
    for(int i=0;i<vertex;i++)
    {
        if(visited[i] == false)
        {
           bfs(adj, visited, ans, i); 
        }
        
    }
    
    return ans;
}