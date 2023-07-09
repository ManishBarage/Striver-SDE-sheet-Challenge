#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int m, int n, int k) {
   
   if(n>m)
        {
            return ninjaAndLadoos(arr2,arr1,n,m,k);
        }
        
        int low = max(0,k-n);
        int high = min(k,m);
        
        while(low <= high)
        {
            int cut1 = (low+high)/2;
            int cut2 = k-cut1;
            
            int left1 = cut1==0 ? INT_MIN : arr1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : arr2[cut2-1];
            
            int right1 = cut1==m ? INT_MAX : arr1[cut1];
            int right2 = cut2==n ? INT_MAX : arr2[cut2];
            
            if(left1 <= right2 && left2 <= right1)
            {
                return max(left1, left2);
            }
            else if(left1 > right2)
            {
                high = cut1-1;
            }
            else
            {
                low = cut1+1;
            }
        }
        return 1;
}