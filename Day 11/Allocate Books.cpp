bool isPossible(int n, int m, vector<int> time,long long int mid)
{
    int studCount=1;
    long long int pageSum=0;
    
    for(int i=0;i<m;i++)
    {
        if(pageSum + time[i] <=mid)
        {
            pageSum +=  time[i];
        }
        else
        {
            studCount++;
            
            if(studCount > n || time[i]>mid)
            {
                return false;
            }
            pageSum = time[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int start = 0;
    long long int sum =0;
    
    for(int i=0;i<time.size();i++)
    {
        sum = sum+time[i];
    }
    
    long long int end = sum;
    
    long long int ans =-1;
    
    while(start<=end)
    {
        long long int mid = start+(end-start)/2;
        if(isPossible(n,m,time,mid))
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
         mid = start+(end-start)/2;
    }
    return ans;
    
}