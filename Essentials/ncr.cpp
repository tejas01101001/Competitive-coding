const int N=1e6+5;
lli fac[N];
void fact()
{
    fac[0]=1;
    for(int i=1;i<N;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    return ;
}
lli ncr(lli a,lli b)
{
    if(a<b||a<0||b<0)
        return 0;
    return ((fac[a]*modi(fac[b],mod))%mod*modi(fac[a-b],mod))%mod;
}
int main()
{
    kira;
    lli n,a,b;
    cin >> n;
    fact();
    while(n--)
    {
        cin>>a>>b;
        cout<<ncr(a,b)<<endl;
    }
    return 0;
}
