lli factors(lli num)
{
    lli count=0;
    lli pp=1;
    while(num%2==0)
    {
        count++;
        num/=2;
    }
    pp*=(pow(2,(count+1))-1);
    for(int i=3;i*i<=num;i+=2)
    {
        count=0;
        while(num%i==0)
        {
            count++;
            num/=i;
        }
        pp*=(pow(i,(count+1))-1)/(i-1);
    }
    if(num>2){
        pp*=(n+1);
    }
    return pp;
}
