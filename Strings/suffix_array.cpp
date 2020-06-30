vector<int> suffix_array(string s)
{
    //O(nlog^2(n))
    s += "$";
    int n = int(s.si);

    //pos is the starting pos of suffix
    //eqc is the equivalence class for a string 
    //a is used to store the strings as a form of numbers
    
    vector<int> pos(n), eqc(n);
    vector<pii> a(n);

    for (int i = 0; i < n; i++)
        a[i] = {s[i], i};
    sort(all(a));

    for (int i = 0; i < n; i++)
        pos[i] = a[i].S;
    eqc[pos[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        eqc[pos[i]] = eqc[pos[i - 1]];
        if (a[i].F != a[i - 1].F)
            eqc[pos[i]]++;
    }

    int k = 0;
    while ((1 << k) < n)
    {
        //Stop the loop when we have n distinct eqc
        vector<pair<pii, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {{eqc[i], eqc[(i + (1 << k)) % n]}, i};
        }
        sort(all(a));

        for (int i = 0; i < n; i++)
            pos[i] = a[i].S;
        eqc[pos[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            eqc[pos[i]] = eqc[pos[i - 1]];
            if (a[i].F != a[i - 1].F)
                eqc[pos[i]]++;
        }
        k++;
    }
    return pos;
}