
int getPivot(int* arr,int size)
{
    int start = 0;
    int end = size-1;
    int mid = start+(end-start)/2;
    
    while(start<end)
    {
        if(arr[mid]>=arr[0])
        {
            start = mid+1;
        }
        else
        {
            end =mid;
        }
        mid = start+(end-start)/2;
    }
    return start;
}

int binarySearch(int* arr,int s,int e,int key)
{
    int start =s;
    int end = e;
    int mid=start+(end-start)/2;
    
    while(start<=end)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key>arr[mid])
        {
            start = mid+1;
        }
        else if(key<arr[mid])
        {
            end = mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}


int search(int* arr, int n, int key) {
    
    int pivot = getPivot(arr,n);
    
    if(key >= arr[pivot] && key<= arr[n-1])
    {
        return binarySearch(arr,pivot,n-1,key);
    }
    else
    {
        return binarySearch(arr,0,pivot-1,key);       
    }
}