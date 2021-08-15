# Factorial and nCr

```C++
const int N = 1e6 + 5;
ll fac[N], invfac[N];
void fact()
{
    invfac[0] = fac[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fac[i] = (fac[i - 1] * i) % mod;
        invfac[i] = modi(fac[i]);
    }
    return;
}

ll ncr(ll a, ll b)
{
    if (a < b || a < 0 || b < 0)
        return 0;
    return ((fac[a] * invfac[b]) % mod * invfac[a - b]) % mod;
}

int main()
{
    kira;
    ll n, a, b;
    cin >> n;
    fact();
    while (n--)
    {
        cin >> a >> b;
        cout << ncr(a, b) << endl;
    }
    return 0;
}
```