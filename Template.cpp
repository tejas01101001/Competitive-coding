//https://codeforces.com/contest/..../problem/.
//Author: BROWNIE TK

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//========================TypeDefs===================================
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;

typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef pair<int, lli> pil;

//=========================MACROS====================================

#define pb              push_back
#define popb            pop_back()
#define pf              push_front
#define popf            pop_front()
#define si              size()
#define be              begin()
#define en              end()
#define all(v)          v.be, v.en
#define mp              make_pair
#define mt              make_tuple
#define acc(v)          accumulate(all(v), 0)
#define F               first
#define S               second

#define forz(i, n)      for (int i = 0; i < n; i++)
#define fore(i, m, n)   for (int i = m; i <= n; i++)
#define rforz(i, n)     for (int i = n - 1; i >= 0; i--)
#define rfore(i, m, n)  for (int i = n; i >= m; i--)

#define deci(n)         fixed << setprecision(n)
#define high(n)         __builtin_popcount(n)
#define highll(n)       __builtin_popcountll(n)
#define parity(n)       __builtin_parity(n)
#define clz(n)          __builtin_clz(n)
#define clzll(n)        __builtin_clzll(n)
#define ctz(n)          __builtin_ctz(n)

#define bset(a, p)      ((a) | (1ll << (p)))
#define bchk(a, p)      ((a) & (1ll << (p)))
#define bxor(a, p)      ((a) ^ (1ll << (p)));
#define brem(a, p)      (bchk(a, p) ? (bxor(a, p)) : (a))

#define lb              lower_bound
#define ub              upper_bound
#define er              equal_range

#define findnot         find_first_not_of

#define maxe            *max_element
#define mine            *min_element

#define mod             1000000007
#define mod2            998244353
#define gcd              __gcd
#define kira            ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define endl            "\n"
#define p0(a)           cout << a << " "
#define p1(a)           cout << a << endl
#define p2(a, b)        cout << a << " " << b << endl
#define p3(a, b, c)     cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d)  cout << a << " " << b << " " << c << " " << d << endl

#define oset            tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetlli         tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>

#define ofk             order_of_key
#define fbo             find_by_order
//member functions :
//1. order_of_key(k) : number of elements sbtriectly lesser than k
//2. find_by_order(k) : k-th element in the set

//==============================FUNCTIONS===========================================

lli power(lli x, lli y, lli p = mod)
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

lli modadd(lli a, lli b, lli m = mod)
{
    a += b;
    if (a >= m)
        a -= m;
    return a;
}

lli modmul(lli a, lli b, lli m = mod)
{
    return ((a % m) * (b % m)) % m;
}

lli modi(lli a, lli m = mod) { return power(a, m - 2, m); }

//================================CODE=============================================

int main()
{
    kira;
    
    return 0;
}