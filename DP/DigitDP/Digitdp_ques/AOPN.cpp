//https://codeforces.com/contest/1326/problem/C
//BROWNIE TK

#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x − 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/

#define lb lower_bound
#define ub upper_bound
#define er equal_range

#define findnot find_first_not_of

#define maxe *max_element
#define mine *min_element

#define mod2 1000000007
#define mod 998244353
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
//member functions :
//1. order_of_key(k) : number of elements sbtriectly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order
using namespace std;

/*STD funcions*/
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
/*CODE BEGINS*/
string s;
lli dp[20][11][11][2][2][2][2];
lli solve(lli pos, lli las, lli slas, lli even, lli odd, lli t, lli st)
{
    if (pos == int(s.si))
        return (even && odd);

    if (dp[pos][las][slas][even][odd][t][st] != -1)
        return dp[pos][las][slas][even][odd][t][st];

    lli ans = 0;
    if (st == 0)
    {
        ans += solve(pos + 1, las, slas, even, odd, t & (s[pos] == '0'), st);
        lli lim = t ? s[pos] - '0' : 9;
        for (lli i = 1; i <= lim; i++)
        {
            ans += solve(pos + 1, i, slas, even, odd , t & (lim== i), 1ll);
        }
    }
    else
    {
        lli lim = t ? s[pos] - '0' : 9;
        for (int i = 0; i <= lim; i++)
        {
            ans += solve(pos + 1, i, las, even |(las == i), odd | (slas == i), t & (lim == i), 1ll);
        }
    }
    return dp[pos][las][slas][even][odd][t][st]=ans;
}
int main()
{
    kira;
    int nt;
    cin >> nt;
    string a, b;
    while (nt--)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        s = a;
        lli y = solve(0,10,10,0,0,1,0);
        memset(dp, -1, sizeof(dp));
        s = b;
        lli x = solve(0,10,10,0,0,1,0);
        cout << x - y << endl;
    }
    return 0;
}
