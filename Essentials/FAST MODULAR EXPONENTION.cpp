FAST MODULAR EXPONENTION
typedef long long int lli;
lli power(lli x,lli y,lli p)
{
	lli res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
			res=(res*x)%p;
		//y must be even now
		y=y>>1; //y=y/2
		x=(x*x)%p;
	}
	return res;
}

MODULAR INVERSE 
lli modi(lli a,lli m)
{
// fermat little thm where m is prime
return power(a,m-2,m);
}