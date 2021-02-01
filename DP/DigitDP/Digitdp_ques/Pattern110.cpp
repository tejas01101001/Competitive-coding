//Binary rep contains 110 as a substring
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
lli dp[65][4][2];
lli solve(int pos, int st, int t)
{
    if (pos == int(s.si))
        return (st == 3);

    if (dp[pos][st][t] != -1)
        return dp[pos][st][t];

    int lim = t ? s[pos] - '0' : 1;
    int nt = t;

    lli ans = 0;
    for (int i = 0; i <= lim; i++)
    {
        if (i != lim)
            nt = 0;
        else
            nt = t;
        int nst;
        if (i == 0)
        {
            if (st == 0)
                nst = 0;
            else if (st == 1)
                nst = 0;
            else if (st == 2)
                nst = 3;
            else if (st == 3)
                nst = 3;
        }
        else
        {
            if (st == 0)
                nst = 1;
            else if (st == 1)
                nst = 2;
            else if (st == 2)
                nst = 2;
            else if (st == 3)
                nst = 3;
        }
        ans += solve(pos+1,nst,nt);
    }
    return dp[pos][st][t]=ans;
}
string tobin(lli n)
{
    string temp="";
    for(lli i=61;i>=0;i--)
    {
        if((1ll<<i)&n)temp+='1';
        else temp+='0';
    }
    return temp;
}
int main()
{
    kira;
    int nc;
    lli l,r;
    cin>>nc;
    while(nc--)
    {
        cin>>l>>r;
        l--;
        memset(dp,-1,sizeof(dp));
        s=tobin(l);
        lli y=solve(0,0,1);
        memset(dp,-1,sizeof(dp));
        s=tobin(r);
        lli x=solve(0,0,1);
        cout<<x-y<<endl;
    }
    return 0;
}
