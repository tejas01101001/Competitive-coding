#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include <vector>
#include <utility>

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifdef local
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

template <typename T>
T extGcd(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

template <typename T>
T modInv(T a, T m)
{
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}

long long crt(const std::vector<std::pair<int, int>> &pp, int mod = -1);

#include <algorithm>

struct FFT_mod
{
    int mod, root, root_1, root_pw;
};

extern FFT_mod suggested_fft_mods[5];
void ntt_shortmod(std::vector<int> &a, bool invert, const FFT_mod &mod_data);

const int mod = 1000000007;

vector<int> mull(const vector<int> &left, const vector<int> &right, const FFT_mod &mod_data)
{
    vector<int> left1 = left, right1 = right;
    ntt_shortmod(left1, false, mod_data);
    ntt_shortmod(right1, false, mod_data);

    for (int i = 0; i < left.size(); i++)
    {
        left1[i] = (left1[i] * 1ll * right1[i]) % mod_data.mod;
    }

    ntt_shortmod(left1, true, mod_data);
    return left1;
}

vector<int> mult(vector<int> &left, vector<int> &right)
{
    int ssss = left.size() + right.size() - 1;
    int pot2;
    for (pot2 = 1; pot2 < ssss; pot2 <<= 1)
        ;

    left.resize(pot2);
    right.resize(pot2);

    vector<int> res[3];
    for (int i = 0; i < 3; i++)
    {
        res[i] = mull(left, right, suggested_fft_mods[i]);
    }

    vector<int> ret(pot2);
    for (int i = 0; i < pot2; i++)
    {
        vector<pair<int, int>> mod_results;
        for (int j = 0; j < 3; j++)
        {
            mod_results.emplace_back(res[j][i], suggested_fft_mods[j].mod);
        }
        ret[i] = crt(mod_results, mod);
    }
    return ret;
}

long long crt(const std::vector<std::pair<int, int>> &a, int mod)
{
    long long res = 0;
    long long mult = 1;

    int SZ = a.size();
    std::vector<int> x(SZ);
    for (int i = 0; i < SZ; ++i)
    {
        x[i] = a[i].first;
        for (int j = 0; j < i; ++j)
        {
            long long cur = (x[i] - x[j]) * 1ll * modInv(a[j].second, a[i].second);
            x[i] = (int)(cur % a[i].second);
            if (x[i] < 0)
                x[i] += a[i].second;
        }
        res = (res + mult * 1ll * x[i]);
        mult = (mult * 1ll * a[i].second);
        if (mod != -1)
        {
            res %= mod;
            mult %= mod;
        }
    }

    return res;
}

FFT_mod suggested_fft_mods[] = {
    {7340033, 5, 4404020, 1 << 20},
    {415236097, 73362476, 247718523, 1 << 22},
    {463470593, 428228038, 182429, 1 << 21},
    {998244353, 15311432, 469870224, 1 << 23},
    {918552577, 86995699, 324602258, 1 << 22}};

int FFT_w[1050000];
int FFT_w_dash[1050000];

inline ll power(ll x, ll y, ll p = mod)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

inline ll modadd(ll a, ll b, ll m = mod)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}

inline ll modmul(ll a, ll b, ll m = mod)
{
    return ((a % m) * (b % m)) % m;
}

inline ll modi(ll a, ll m = mod) { return power(a, m - 2, m); }

const int N = 5e3 + 5;
long long fac[N], invfac[N];
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

void ntt_shortmod(std::vector<int> &a, bool invert, const FFT_mod &mod_data)
{
    // only use if mod < 5*10^8
    int n = (int)a.size();
    int mod = mod_data.mod;

    for (int i = 1, j = 0; i < n; ++i)
    {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            std::swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        int wlen = invert ? mod_data.root_1 : mod_data.root;
        for (int i = len; i < mod_data.root_pw; i <<= 1)
            wlen = int(wlen * 1ll * wlen % mod_data.mod);

        long long tt = wlen;
        for (int i = 1; i < len / 2; i++)
        {
            FFT_w[i] = tt;
            FFT_w_dash[i] = (tt << 31) / mod;
            int q = (FFT_w_dash[1] * 1ll * tt) >> 31;
            tt = (wlen * 1ll * tt - q * 1ll * mod) & ((1LL << 31) - 1);
            if (tt >= mod)
                tt -= mod;
        }
        for (int i = 0; i < n; i += len)
        {
            int uu = a[i], vv = a[i + len / 2] % mod;
            if (uu >= 2 * mod)
                uu -= 2 * mod;
            a[i] = uu + vv;
            a[i + len / 2] = uu - vv + 2 * mod;

            for (int j = 1; j < len / 2; ++j)
            {
                int u = a[i + j];
                if (u >= 2 * mod)
                    u -= 2 * mod;
                int q = (FFT_w_dash[j] * 1ll * a[i + j + len / 2]) >> 31;
                int v = (FFT_w[j] * 1ll * a[i + j + len / 2] - q * 1ll * mod) & ((1LL << 31) - 1);
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v + 2 * mod;
            }
        }
    }
    if (invert)
    {
        int nrev = modInv(n, mod);
        for (int i = 0; i < n; ++i)
            a[i] = int(a[i] * 1ll * nrev % mod);
    }
}

/*
 https://codedrills.io/problems/unique-strings
 Solution to the above question given in the main function
*/

int main()
{
    string s;
    cin >> s;
    fact();
    int n = int(s.size());
    int cnt[26] = {0};
    for (auto c : s)
    {
        cnt[c - 'a']++;
    }

    priority_queue<pair<int, vector<int>>> pq;
    for (int ch = 0; ch < 26; ch++)
    {
        vector<int> v;
        for (int i = 0; i <= cnt[ch]; i++)
        {
            int temp = invfac[i];
            v.push_back(temp);
        }
        debug(v);
        pq.push(make_pair(-int(v.size()), v));
    }

    for (int i = 0; i < 25; i++)
    {
        vector<int> big = pq.top().second;
        pq.pop();
        vector<int> small = pq.top().second;
        pq.pop();

        vector<int> final = mult(big, small);
        pq.push(make_pair(-int(final.size()), final));
    }
    vector<int> res = pq.top().second;
    debug(res);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = modadd(ans, modmul(res[i], fac[i]));
    }
    cout << ans;

    return 0;
}