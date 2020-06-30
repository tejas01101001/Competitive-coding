void count_sort(vector<int> &pos, vector<int> &eqc)
{
    int n = int(pos.size());
    vector<int> cnt(n, 0);

    for (auto x : eqc)
        cnt[x]++;

    vector<int> pos_new(n), start_id(n);
    start_id[0] = 0;

    for (int i = 1; i < n; i++)
    {
        start_id[i] = start_id[i - 1] + cnt[i - 1];
    }

    for (auto x : pos)
    {
        int i = eqc[x];
        pos_new[start_id[i]] = x;
        start_id[i]++;
    }

    pos = pos_new;
    return;
}

vector<vector<int>> suffix_lcp(string s)
{
    //First vector returned is suffix_array
    //Second vector returned is lcp_array
    //O(nlog(n))
    s += "$";
    int n = int(s.si);

    //pos is the starting pos of suffix
    //eqc is the equivalence class for a string

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
        //Position shifted to preserve order of right halfs.
        //When transition form k-->k+1 is done

        for (int i = 0; i < n; i++)
        {
            pos[i] = (pos[i] - (1 << k) + n) % n;
        }

        //Sort the left halfs using counting sort
        count_sort(pos, eqc);

        vector<int> eqc_new(n);
        eqc_new[pos[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            pii prev = {eqc[pos[i - 1]], eqc[(pos[i - 1] + (1 << k)) % n]};
            pii now = {eqc[pos[i]], eqc[(pos[i] + (1 << k)) % n]};
            eqc_new[pos[i]] = eqc_new[pos[i - 1]];
            if (prev != now)
                eqc_new[pos[i]]++;
        }
        eqc = eqc_new;
        k++;
    }

    vector<int> lcp(n);
    k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int pos_i = eqc[i];
        int j = pos[pos_i - 1];
        while (s[i + k] == s[j + k])
            k++;
        lcp[pos_i] = k;
        k = max(k - 1, 0);
    }
    //lcp[i]=lcp(s[i..],s[j...])
    //lcp indexed form 1...n-1
    
    return {pos, lcp};
}