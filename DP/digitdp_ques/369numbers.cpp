//https://www.spoj.com/problems/NUMTSN/
//BROWNIE TK

#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;


#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()

#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en

#define le length()
#define mp make_pair
#define mt make_tuple
#define acc(v) accumulate(all(v), 0)
#define F first
#define S second

#define pll pair<lli, lli>
#define pii pair<int, int>
#define pil pair<int, lli>

#define forz(i, n) for (int i = 0; i < n; i++)
#define fore(i, m, n) for (int i = m; i <= n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rfore(i, m, n) for (int i = n; i >= m; i--)

#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)

#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))

#define lb lower_bound
#define ub upper_bound
#define er equal_range

#define findnot find_first_not_of

#define maxe *max_element
#define mine *min_element

#define mod 1000000007
#define mod2 998244353
#define gcd __gcd
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetlli tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>

#define ofk order_of_key
#define fbo find_by_order
using namespace std;


lli power(lli x, lli y, lli p)
{
    lli res = 1;
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
lli modi(lli a, lli m) { return power(a, m - 2, m); }

string s;
lli dp[51][18][18][18][2];
lli solve(int pos, int s3, int s6, int s9, int t)
{
    if (s3 >= 17 || s6 >= 17 || s9 >= 17)
        return 0;
    int k = int(s.si);
    if (pos == k)
    {
        if (s3 == s6 && s6 == s9 && s3 >= 1)
            return 1;
        return 0;
    }

    if (dp[pos][s3][s6][s9][t] != -1)
        return dp[pos][s3][s6][s9][t];

    int lim = t ? s[pos] - '0' : 9;
    int nt = t;
    lli ans = 0;
    for (int i = 0; i <= lim; i++)
    {
        if (i != lim)
            nt = 0;
        else
            nt = t;
        ans = (ans + solve(pos + 1, s3+(i==3), s6+(i==6), s9+(i==9), nt) % mod) % mod;
        
    }
    return dp[pos][s3][s6][s9][t] = ans;
}
int main()
{
    kira;
    int nc;
    string a, b;
    cin >> nc;
    while (nc--)
    {
        cin >> a >> b;
        int i = int(a.si) - 1;
        while (a[i] == '0')
        {
            a[i] = '9';
            i--;
        }
        a[i]--;
        memset(dp, -1, sizeof(dp));
        s = a;
        lli y = solve(0, 0, 0, 0, 1);
        memset(dp, -1, sizeof(dp));
        s = b;
        lli x = solve(0, 0, 0, 0, 1);
        
        cout << (x - y + mod) % mod << endl;
    }
    return 0;
}
