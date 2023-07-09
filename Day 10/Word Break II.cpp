#include <bits/stdc++.h> 

void solve(int in, string ds, map<string, int> &m, string &s, vector<string> &ans){

    if(in == s.size()){

        ans.push_back(ds);

        return;

    }

    for(int i = in; i < s.size(); i++){

        string tmp = s.substr(in, i - in + 1);

        if(m[tmp] >= 1){

            int n = ds.size();

            ds += tmp + " ";

            solve(i + 1, ds, m, s, ans);

            ds.erase(n);

        }

    }

}

vector<string> wordBreak(string &s, vector<string> &dictionary)

{

    vector<string> ans;

    map<string, int> m;

    for(int i = 0; i < dictionary.size(); i++ ){

        m[dictionary[i]]++;

    }

    solve(0, "", m, s, ans);

    return ans;

}