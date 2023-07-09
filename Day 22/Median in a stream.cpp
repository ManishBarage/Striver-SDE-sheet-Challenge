#include<queue>

int signum(int a, int b)
{
    if(a==b)
    {
        return 0;
    }
    else if(a>b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void getMedian(int element, priority_queue<int> &max,priority_queue<int, vector<int>, greater<int> > &min, int &median )
{
    switch(signum(max.size(), min.size()))
    {
        case 0:
            if(element > median)
            {
                min.push(element);
                median = min.top();
            }
            else
            {
                max.push(element);
                median = max.top();
            }
            break;
        
         case 1:
            if(element > median)
            {
                min.push(element);
                median = (max.top() + min.top())/2;
            }
            else
            {
                min.push(max.top());
                max.pop();
                max.push(element);
                median = (max.top() + min.top())/2;
            }
            break;
            
        case -1:
            if(element > median)
            {
                max.push(min.top());
                min.pop();
                min.push(element);
                
                median = (max.top() + min.top())/2;
            }
            else
            {
                max.push(element);
                median = (max.top() + min.top())/2;
            }
            break;
            
    }
}



vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
    
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;
    int median = 0;
    
	for(int i=0;i<n;i++)
    {
        int element = arr[i];
        getMedian(element, maxheap, minheap, median);
        ans.push_back(median);
    }
    
    return ans;
}
