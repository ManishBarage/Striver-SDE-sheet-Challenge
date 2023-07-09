#include <bits/stdc++.h> 

class data
{
    public:
    int val, apos,vpos;
    
    data(int v , int ap, int vp)
    {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct myComp
{
    bool operator()(data &d1, data &d2)
    {
        return d1.val > d2.val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<data , vector<data> , myComp> pq;
    
    for(int i=0; i<k;i++)
    {
        data d(kArrays[i][0], i, 0);
        pq.push(d);
    }
    
    while(!pq.empty())
    {
        data curr = pq.top();
        pq.pop();
        ans.push_back(curr.val);
        
        int ap = curr.apos;
        int vp = curr.vpos;
        
        if(vp+1 < kArrays[ap].size())
        {
            data d(kArrays[ap][vp+1], ap, vp+1);
            pq.push(d);
        }
        
    }
    return ans;
}
