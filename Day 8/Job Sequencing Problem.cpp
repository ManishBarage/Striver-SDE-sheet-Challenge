#include <bits/stdc++.h> 

bool cmp(vector<int>a, vector<int>b)
{
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);

    int n = jobs.size();
    int maxi = 0;

    for(int i=0;i<n;i++)
    {
        maxi = max(maxi, jobs[i][0]);
    }

    int jobProfit =0;

    vector<int> ans(maxi+1, -1);

    for(int i=0;i<n;i++)
    {
        int curdead = jobs[i][0];
        int curProf = jobs[i][1];

        for(int j=curdead;j>0;j--)
        {
            if(ans[j] == -1)
            {
                ans[j] = 1;
                jobProfit +=curProf;
                break;

            }
        }
    }

    return jobProfit;
}
