
int phi[105][26];
int match(string t, string s)
{
    int m = int(t.size());
    int n = int(s.size());
    for (int i = n - m; i < n; i++)
    {
        if (s[i] != t[i + m - n])
            return 0;
    }
    return 1;
}

int presuf(string t, string s)
{
    int m = int(t.size());
    for (int i = int(s.size()); i >= 1; i--)
    {
        if (match(t.substr(0, i), s))
            return i;
    }
    return 0;
}

void dfa(string s)
{
    int m = int(s.size());
    vector<string> v(m + 1, "");
    for (int i = 1; i <= m; i++)
    {
        v[i] = v[i - 1];
        v[i] += s[i - 1];
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= 25; j++)
        {
            //'A' uppercase chars considered
            phi[i][j] = presuf(s, v[i] + char('A' + j));
            if (i == m)
                phi[i][j] = m;
        }
    }
    return;
}
