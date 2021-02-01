//https://codeforces.com/contest/1327/problem/A
//BROWNIE TK

#include <bits/stdc++.h>
using namespace std;

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
//member functions :
//1. order_of_key(k) : number of elements sbtriectly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order

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
const int N = 1e5 + 5;
lli ten[N];
pll dp[N][10][2];
void pre()
{
    ten[0] = 1;
    for (int i = 1; i < N; i++)
    {
        ten[i] = (ten[i - 1] * 10ll) % mod;
    }
    return;
}
pll solve(lli pos, lli dig, lli t)
{
    lli k = lli(s.si);
    if (pos == k)
        return {0, 1};

    if (dp[pos][dig][t].F != -1)
        return dp[pos][dig][t];

    lli lim = t ? s[pos] - '0' : 9;
    pll ans = {0, 0};
    for (lli i = 0; i <= lim; i++)
    {

        pll temp = solve(pos + 1, i, t & (i == lim));
        ans.S = (ans.S + temp.S) % mod;
        ans.F = (ans.F + temp.F) % mod;

        if (i != dig)
        {
            ans.F += (((i * ten[k - pos - 1]) % mod) * temp.S) % mod;
            ans.F %= mod;
        }
    }
    return dp[pos][dig][t] = ans;
}
int main()
{
    kira;
    lli nc, nl, nr;
    string l, r;
    cin >> nc;
    pre();
    while (nc--)
    {
        cin >> nl >> l;
        cin >> nr >> r;
        int i1 = nl - 1;
        while (l[i1] == '0')
        {
            l[i1] = '9';
            i1--;
        }
        l[i1]--;
        forz(i, nl)
        {
            forz(j, 10)
            {
                forz(k, 2)
                {
                    dp[i][j][k].F = -1;
                }
            }
        }
        s = l;
        lli y = solve(0, 0, 1).F;
        forz(i, nr)
        {
            forz(j, 10)
            {
                forz(k, 2)
                {
                    dp[i][j][k].F = -1;
                }
            }
        }
        s = r;
        lli x = solve(0, 0, 1).F;
        cout << (x - y + mod) % mod << endl;
    }
    return 0;
}
