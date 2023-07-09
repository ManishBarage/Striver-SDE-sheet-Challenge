#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int n =p.size();
    int m = s.size();

    if(n==0)
    {
        return false;
    }

    if(n > m)
    {
        return false;
    }

    int count =0;

    for(int i=0;i<m;i++)
    {
        string sub = s.substr(i,n);
        if(sub == p)
        {
            count++;
        }
    }

    if(count>0)
    {
        return true;
    }
    return false;
}