double median(vector<int> &a, vector<int> &b)
{

    int n = a.size();

    int m = b.size();

    vector<int> v;

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    int i = 0;

    int j = 0;

    while (i < n && j < m)

    {

        if (a[i] < b[j])

        {

            v.push_back(a[i]);

            i++;
        }

        else
        {

            v.push_back(b[j]);

            j++;
        }
    }

    while (i < n)

    {

        v.push_back(a[i]);

        i++;
    }

    while (j < m)

    {

        v.push_back(b[j]);

        j++;
    }

    // cout<<v.size();

    double med = 0;

    int mid = (0 + v.size()) / 2;

    if (v.size() % 2 == 0)

    {

        med = (v[mid] + v[mid - 1]) / 2.00;

        return med;
    }

    else
    {

        med = v[mid];

        return med;
    }
}