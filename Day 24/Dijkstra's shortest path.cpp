#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    //Creation of adjanency list
    unordered_map<int,list<pair<int,int>>>adj;

    for(int i=0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2]; //weight

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));

    }

    //Distance arry with initial value as infinity

    vector<int>distance(vertices, INT_MAX);

    //Set with info as (distnace, node)
    set<pair<int,int>>s;

    distance[source]=0;
    s.insert({0,source});

    while(!s.empty())
    {
        // fetch top record

        auto top = *(s.begin());

        int nodeDis = top.first;
        int topNode = top.second;

        //Remove the top record
        s.erase(s.begin());

        for(auto neighbours :adj[topNode])
        {
            if(nodeDis + neighbours.second < distance[neighbours.first])
            {

                //find record in set
                auto record = s.find({distance[neighbours.first], neighbours.first});

                //if record found
                if(record != s.end())
                {
                    s.erase(record);
                }


                //Upadate the distance
                distance[neighbours.first] = nodeDis + neighbours.second;

                //push the record in set
                s.insert({distance[neighbours.first], neighbours.first});
            }
        }
    }

    return distance;
}
