//https://codeforces.com/problemset/problem/1036/C
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
#define F first
#define S second

#define forz(i, n) for (int i = 0; i < n; i++)
#define forzm(i, m, n) for (int i = m; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rforzm(i, m, n) for (int i = n - 1; i >= m; i--)
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define maxe *max_element
#define mine *min_element
#define mod 1000000007
#define mod2 998244353
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
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order

using namespace std;

/*STD fucntions*/
lli power(lli x, lli y, lli p)
{
    lli res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        //y must be even now
        y = y >> 1; //y=y/2
        x = (x * x) % p;
    }
    return res;
}
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
lli lcm(lli a, lli b)
{
    return a * b / gcd(a, b);
}
lli modi(lli a, lli m)
{
    // fermat little thm where m is prime
    return power(a, m - 2, m);
}
/*CODE BEGINS*/
string s;
lli dp[20][5][2];
lli solve(int pos, int cnt, int t)
{
    if (cnt >= 4)
        return 0;
    if (pos == s.si)
    {
        return 1;
    }
    if (dp[pos][cnt][t] != -1)
        return dp[pos][cnt][t];
    int lim = (t) ? 9 : s[pos] - '0';
    lli ans = 0, nt = t;
    for (int i = 0; i <= lim; i++)
    {
        if (i != lim)
            nt = 1;
        else
            nt = t;
        if (i != 0)
            ans += solve(pos + 1, cnt + 1, nt);
        else
            ans += solve(pos + 1, cnt, nt);
    }
    return dp[pos][cnt][nt] = ans;
}
int main()
{
    kira;
    lli t, l, r;
    string a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int l = a.si - 1;
        while (a[l] == '0')
        {
            a[l] = '9';
            l--;
        }
        a[l]--;
        memset(dp, -1, sizeof(dp));
        s = a;
        l = solve(0, 0, 0);
        memset(dp, -1, sizeof(dp));
        s = b;
        r = solve(0, 0, 0);
        p1(r - l);
    }
    return 0;
}
