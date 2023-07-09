bool detect(int src,vector<bool>&vis,vector<bool>&curVis,vector<int>adj[])
{
  vis[src]= true;
  curVis[src]= true;

  for(auto i:adj[src])
  {
    if(!vis[i])
    {
      if(detect(i,vis,curVis,adj))
      {
        return true;
      }

    }
    else if(curVis[i])
    {
      return true;
    }
  }

  curVis[src]= false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  vector<int>adj[n+1];

  for(auto x:edges)
  {
   
    int a =x.first;
    int b = x.second;

    adj[a].push_back(b);
  }

  vector<bool>vis(n+1, false);
  vector<bool>curVis(n+1 ,false);

  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      if(detect(i,vis,curVis,adj))
      {
        return true;
      }
    }
  }

  return false;

}