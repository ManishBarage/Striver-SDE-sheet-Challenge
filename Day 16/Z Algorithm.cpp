int zAlgorithm(string s, string p, int n, int m)
{
    if (m == 0)
    {
        return 0;
    }

    if (n < m)
    {
        return -1;
    }

    int count = 0;

    for (int i = 0; i <= (n - m); i++)
    {
        bool isMatch = true;

        for (int j = 0; j < m; j++)
        {
            if (p[j] != s[j + i])
            {
                isMatch = false;
                break;
            }
        }
        if (isMatch)
        {
            count++;
        }
    }

    return count;
}