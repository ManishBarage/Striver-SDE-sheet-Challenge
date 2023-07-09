#include <bits/stdc++.h> 
bool isPossible(vector<int> pos , int players, int mid)
{
	int count =1;
	int lastPos = pos[0];

	for(int i=0;i<pos.size();i++)
	{
		if(pos[i]-lastPos >= mid)
		{
			count++;
			if(count == players)
			{
				return true;
			}

			lastPos = pos[i];
		}
	}

	return false;
}
int chessTournament(vector<int> pos , int n ,  int c){
	
	sort(pos.begin(), pos.end());

	int start = 0;
	int end = -1;

	for(int i=0;i<n;i++)
	{
		end = max(end, pos[i]);
	}

	int ans = -1;

	while(start <= end)
	{
		int mid = (start+end)/2;

		if(isPossible(pos,c,mid))
		{
			ans = mid;
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}

	return ans;
}