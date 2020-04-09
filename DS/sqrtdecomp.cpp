1)In practice, it is not necessary to use the exact value of sqrt(n) as a parameter and instead we may use parameters k and n / k where k is different from sqrt(n) .
2)The optimal parameter depends on the problem and input. For example, if an algorithm often goes through the blocks but rarely inspects single elements inside the blocks, it may be a good idea to divide the array into k < sqrt(n) blocks, each of which contains n / k > sqrt(n) elements.

int main()
{
    kira;

    int n, q;
    cin >> n >> q;
    vector<lli> a(n);
    forz(i, n) cin >> a[i];

    int len = int(sqrt(n + .0)) + 1;
    vector<lli> b(len);

    for (int i = 0; i < n; i++)
    {
        b[i / len] += a[i];
    }

    int l, r;
    while (q--)
    {
        //l,r zero based in our algorithm
        cin >> l >> r;
        l--,r--;

        lli sum = 0;
        int low = l / len, high = r / len;

        if (low == high)
        {
            for (int i = l; i <= r; i++)
                sum += a[i];
        }
        else
        {
            for (int i = l; i <= (low + 1) * len - 1; i++)
                sum += a[i];
            for (int i = low + 1; i <= high - 1; i++)
                sum += b[i];
            for (int i = high * len; i <= r; i++)
                sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}