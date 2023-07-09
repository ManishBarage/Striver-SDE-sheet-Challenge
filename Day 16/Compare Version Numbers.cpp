#include <bits/stdc++.h> 
#include<vector>
int compareVersions(string a, string b) 
{
    // Write your code here
   
    vector<string>v1, v2;
    
    string temp="";
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='.')
        {
            v1.push_back(temp);
            temp="";
        }
        else
        {
            temp+=a[i];
        }
    }
    v1.push_back(temp);
    temp="";
    for(int i=0;i<b.size();i++)
    {
        if(b[i]=='.')
        {
            v2.push_back(temp);
            temp="";
        }
        else
        {
            temp+=b[i];
        }
    }
    v2.push_back(temp);
    temp="";
    
    int n=v1.size();
    int m=v2.size();
    
    for(int i=0;i<max(n,m);i++)
    {
    
        string str1=i<n?v1[i]:"0";
        string str2=i<m?v2[i]:"0";
        if(str1 > str2)
        {
            if(str2.size()>str1.size())
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        else if(str2 > str1)
        { 
            if(str1.size()>str2.size())
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    return 0;
}