
void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,  vector<int> &res, int node)
{
    //Store node in ans;
    res.push_back(node);
    visited[node] = true;
    
    //Recursive call for each connected node
    for(auto i:adj[node])
    {
        if(visited[i] == false)
        {
            dfs(adj, visited, res, i);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //Create adjacency list
    unordered_map<int, list<int>> adj;
    
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
 
    for(int i=0;i<V;i++)
    {
        if(visited[i] == false)
        {
             vector<int> res;
             dfs(adj, visited, res,i);
             ans.push_back(res);
        }       
    }
    
    return ans;
    
}