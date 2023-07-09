#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int, vector<int>,greater<int>>pq;
    int sz;
    Kthlargest(int k, vector<int> &arr) {
       sz = k;

       for(int i=0;i<arr.size();i++)
       {
           pq.push(arr[i]);
       }
    }

    void add(int num) {
        pq.push(num);
    }

    int getKthLargest() {
       while(pq.size() > sz)
       {
           pq.pop();
       }
       return pq.top();
    }

};