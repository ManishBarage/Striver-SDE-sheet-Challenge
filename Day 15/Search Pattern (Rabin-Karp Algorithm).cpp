vector<int> stringMatch(string &str, string &pat)
{

    vector<int> result;

    int n = str.size(), m = pat.size();

    for (int i = 0; i < n; i++)
    {

        if (str[i] == pat[0])
        {

            if (str.substr(i, m) == pat)
            {

                result.push_back(i);
            }
        }
    }

    return result;
}