int removeDuplicates(vector<int> &arr, int n) {
	int count=0;

	int i=0,j=i+1;

	while(j<n)
	{
		if(arr[i] == arr[j])
		{
			count++;
			i++;j++;
		}
		else{
			i++;j++;
		}
	}

	return n-count;
}