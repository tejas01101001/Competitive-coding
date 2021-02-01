for (int b = 0; b < (1 << n); b++)
{
    vector<int> subset;
    //IF THE ith BIT IS SET THEN IT BELONGS TO THE SUBSET
    for (int i = 0; i < n; i++)
    {
        if (b & (1 << i))
            subset.pb(i);
    }
}