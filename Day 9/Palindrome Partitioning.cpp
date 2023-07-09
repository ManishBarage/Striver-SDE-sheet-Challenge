#include <bits/stdc++.h> 
bool isPalindrome(string s)
{
    int start =0;
    int end = s.size()-1;
    
    while(start <= end)
    {
        if(s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    
    return true;
}

void solve(string s, vector<vector<string>> &ans, vector<string> &temp )
{
   if(s.size() ==0)
   {
       ans.push_back(temp);
       return;
   }
    
    for(int i=1;i<=s.size();i++)
    {
        string left = s.substr(0,i);
        
        if(isPalindrome(left))
        {
            temp.push_back(left);
            string right =s.substr(i);
            solve(right, ans, temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> temp;
    
    solve(s, ans, temp);
    return ans;
    
   
}