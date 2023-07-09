#include<bits/stdc++.h>

bool cmp(pair<int,int>a, pair<int,int>b)
{
    return a.second < b.second;
}

int maximumActivities(vector<int> &start, vector<int> &end) {

    vector<pair<int,int>>arr;

    for(int i=0;i<start.size();i++)
    {
        pair<int,int> p = make_pair(start[i], end[i]);
        arr.push_back(p);
    }

    sort(arr.begin(), arr.end(), cmp);

    int count =1;
    int endAns = arr[0].second;

    for(int i=1;i<start.size();i++)
    {
        if(arr[i].first >= endAns)
        {
            count++;
            endAns = arr[i].second;
        }
    }

    return count;

    
}