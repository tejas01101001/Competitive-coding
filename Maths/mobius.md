# Mobius Inversion 

- Refer to the pdf for the theory 
- [Counting Co-prime Pairs](https://cses.fi/problemset/task/2417)
  
```C++
const int N = 1e6 + 5;
int spf[N + 1];
int mobi[N + 1];
lli cnt[N + 1];
vector<int> prime;
 
void linear_sieve()
{
	//spf:Smallest prime factor
	for (int i = 2; i <= N; ++i)
	{
		if (spf[i] == 0)
		{
			spf[i] = i;
			prime.pb(i);
		}
		for (int j = 0; j < int(prime.si) && prime[j] <= spf[i] && i * prime[j] <= N; j++)
			spf[i * prime[j]] = prime[j];
	}
}
 
void mobius()
{
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
			mobi[i] = 1;
		else if (spf[i] == spf[i / spf[i]])
			mobi[i] = 0;
		else
			mobi[i] = -1 * mobi[i / spf[i]];
	}
}
```