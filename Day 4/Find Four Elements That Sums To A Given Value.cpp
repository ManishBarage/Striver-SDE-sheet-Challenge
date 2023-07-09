#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n) {
    set<vector<int>>s;
        string ans="";

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++)
        {
            if(i>0 and nums[i] == nums[i-1])
            {
                continue;
            }

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 and nums[j] == nums[j-1])
                {
                    continue;
                }

                int left =j+1;
                int right = n-1;

                while(left <right)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right];

                    if(sum > target)
                    {
                        right--;
                    } else if (sum == target) {
                      return "Yes";
                
                    }
                    else
                    {
                        left++;
                    }
                }
            }
        }

        return "No";


}
