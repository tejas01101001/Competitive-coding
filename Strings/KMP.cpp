int pi[100];

void lps(string s)
{
    int n = int(s.si);
    for (int q = 1; q < n; q++)
    {
        int k = pi[q - 1];

        while (k > 0 && s[q] != s[k])
            k = pi[k - 1];

        pi[q] = k + (s[k] == s[q] ? 1 : 0);
    }
}

vector<int> kmp_occurances(string t, string p)
{
    string s = p + '#' + t;
    int n = int(s.si);
    int m = int(p.si);

    lps(s);
    vector<int> v;

    for (int i = m + 1; i < n; i++)
    {
        if (pi[i] == m)
        {
            v.pb(i - 2 * m);
        }
    }

    return v;
}
