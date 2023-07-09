#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
   if(input.length()==0)
   {
       return 0;
   }

   int maxAns = INT_MIN;

   int l=0;
   unordered_set<char>s;

   for(int i=0;i<input.length();i++)
   { 

       if(s.find(input[i])!= s.end());
       {
           while(l<i and s.find(input[i])!= s.end())
           {
               s.erase(input[l]);
               l++;
           }
       }

       s.insert(input[i]);
       maxAns = max(maxAns,i-l+1);
   }

   return maxAns;
}