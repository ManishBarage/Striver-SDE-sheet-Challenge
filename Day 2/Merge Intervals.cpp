#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    vector<vector<int>>ans;

    for(int i=0;i<n;i++)
    {
        if(ans.empty())
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            vector<int>&v = ans.back();
            int y = v[1];

            if(intervals[i][0] <= y)
            {
                v[1] = max(intervals[i][1],y);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
    }

    return ans;
}
