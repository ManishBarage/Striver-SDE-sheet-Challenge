#include<bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

  vector< vector<int> > ans;

   sort(arr.begin(),arr.end());

   set<vector<int>>s;

   for(int i=0;i<n-2;i++)
   {
     int j =i+1;
     int k = n-1;

     while(j<k)
     {
       if(arr[i]+arr[j]+arr[k] == K)
       {
         s.insert({arr[i], arr[j], arr[k]});
         j++;
         k--;
       }
       else if(arr[i]+arr[j]+arr[k] > K)
       {
         k--;
       }
       else
       {
         j++;
       }
     }
   }

   for(auto x:s)
   {
     ans.push_back(x);
   }

   return ans;

}