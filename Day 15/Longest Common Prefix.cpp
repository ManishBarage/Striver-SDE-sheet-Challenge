string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    for(int i=0;i<arr[0].length();i++)
    {
        // Take First String and its each element with characters or remianing strings
        char ch = arr[0][i];
        
        bool match = true;
        for(int j=1;j<n;j++)
        {
            if(arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        
        if( match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}


