
int minCharsforPalindrome(string str) {
	int i=0;
	int j= str.size()-1;
	int temp =j;
	int count =0;

	while(i <j)
	{
		if(str[i] == str[j])
		{
			i++;
			j--;
		}
		else{
			count++;
			i=0;
			temp--;
			j=temp;
		}
	}

	return count;
	
}
