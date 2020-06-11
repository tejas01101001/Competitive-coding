const int N = 1e7;
int spf[N + 1];
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