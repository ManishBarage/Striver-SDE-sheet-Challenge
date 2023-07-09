#include <bits/stdc++.h> 

void solve(string str, vector<string> &ans, int index)
{
    if(index >= str.size())
    {
        ans.push_back(str);
        return;
    }
    
    for(int i=index;i<str.size();i++)
    {
        swap(str[index], str[i]);
        //Recursion
        solve(str, ans, index+1);
        //Backtracking
        swap(str[index], str[i]);
    }
}
vector<string> findPermutations(string &s) {
    
    vector<string> ans;
    int index =0;
    
    solve(s, ans, index);
    return ans;
}