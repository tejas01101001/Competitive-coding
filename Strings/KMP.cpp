int pi[100];

void lps(string s)
{
    int m = int(s.si);
    int k = 0;
    int i = 1;
    while (i < m)
    {
        if (s[i] == s[k])
        {
            pi[i] = ++k;
            i++;
        }
        else
        {
            if (k != 0)
            {
                k = pi[k - 1];
            }
            else
            {
                pi[i] = 0;
                i++;
            }
        }
    }
    return;
}
bool kmp(string t, string p)
{
    int n = int(t.si);
    int m = int(p.si);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (t[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = pi[j - 1];
            }
            else
                i++;
        }
    }
    if (j == m)
        return true;
    return false;
}
