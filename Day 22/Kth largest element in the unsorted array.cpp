#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	priority_queue<int>pq;

	for(int i=0;i<size;i++)
	{
		pq.push(arr[i]);
	}
	K = K-1;
	while(K)
	{
		pq.pop();
		K--;
	}

	return pq.top();
}