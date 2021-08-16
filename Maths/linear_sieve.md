# Sieve for Prime Identification

## Sieve of Eratosthenes

- Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1,n] using O(nloglogn) operations.
- Algorithm visualization    
![Sieve for [1,16]](https://cp-algorithms.web.app/img/sieve_eratosthenes.png)
- Since we iterate over the prime numbers in order, we already marked all numbers, who are divisible by at least one of the prime numbers, as divisible.
- 
```C++
int n;
vector<bool> is_prime(n + 1, true);
is_prime[0] = is_prime[1] = false;

for (int i = 2; i * i <= n; i++)
{
	if (is_prime[i])
	{
		for (int j = i * i; j <= n; j += i)
			is_prime[j] = false;
	}
}
```
## Linear sieve O(n) also stores the smallest prime factor

- In practice we run the inner loop for a composite multiple times due to the fact that it has multiple factors. 
- Thus, if we can establish a unique representation for each composite and pick them out only once, our algorithm will be somewhat better. 
- Note that every composite q must have at least one prime factor, so we can pick the smallest prime factor p, and let the rest of the part be i, i.e. q = ip. 
- Since p is the smallest prime factor, we have i ≥ p, and no prime less than p can divide i. 
- Now let us take a look at the code we have a moment ago. 
- When we loop for every i, all primes not exceeding i is already recorded in the container prime. 
- Therefore, if we only loop for all elements in prime in the inner loop, breaking out when the element divides i, we can pick out each composite exactly once.
  
```C++
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
			prime.push_back(i);
		}
		for (int j = 0; j < int(prime.si) && prime[j] <= spf[i] && i * prime[j] <= N; j++)
			spf[i * prime[j]] = prime[j];
	}
}
```
## Prime factorization for a given number O(log n)

- We can get all the prime factors of a given number in O(log n) by using the linear sieve
  
```C++
vector<int> get_factors(int n)
{
	vector<int> ans;
	while (n != 1)
	{
		ans.push_back(spf[n]);
		n /= spf[n];
	}
	return ans;
}
```