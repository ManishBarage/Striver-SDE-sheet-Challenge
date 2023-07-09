#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    unordered_map<char,int>mp1,mp2;

    for(int i=0;i<str1.size();i++)
    {
        mp1[str1[i]]++;
    }

    for(int i=0;i<str2.size();i++)
    {
        mp2[str2[i]]++;
    }

    for(auto i:mp1)
    {
        if(mp2.find(i.first) ==mp2.end() and i.second != mp2[i.first] )
        {
            return false;
        }
    }
    return true;


}