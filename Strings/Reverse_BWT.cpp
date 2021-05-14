// https://www.geeksforgeeks.org/inverting-burrows-wheeler-transform/

    string s;
    cin >> s;
    vector<int> v;
    vector<int> a[26];
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
            v.push_back(i);
        else
            a[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++)
    {
        for (auto j : a[i])
            v.push_back(j);
    }
    string ans;
    int i = v[v[0]];
    while (s[i] != '#')
    {
        ans += s[i];
        i = v[i];
    }
    cout << ans;