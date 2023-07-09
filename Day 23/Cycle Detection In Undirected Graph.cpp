#include<unordered_map>
#include<list>
#include<queue>

bool detectCycle(int src, unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited)
{
    unordered_map<int, int> parent;
    queue<int>q;
    
    parent[src]= -1;
    q.push(src);
    visited[src] = true;
    
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        for(auto neighbour : adj[frontNode])
        {
            if(visited[neighbour] == true && neighbour != parent[frontNode])
            {
                return true;
            }
            else if(visited[neighbour] == false)
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjacency list
    unordered_map<int, list<int>> adj;
    
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    //to handle disconnected components
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
       if(visited[i] == false)
       {
            bool ans = detectCycle(i, adj, visited);
            if(ans == true)
            {
                return "Yes";
            }
       }
    }
    return "No";
}
   
