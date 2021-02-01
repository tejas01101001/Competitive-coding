1)There are many types of problems that ask to count the number
of integers ‘x‘ between two integers say ‘a‘ and ‘b‘ such that 
x satisfies a specific property that can be related to its digits.

2)G(x) tells the number of such integers between 1 to x 
(inclusively), then the number of such integers between a and b 
can be given by G(b) – G(a-1).

3)tn tn-1 tn-2 … t2 t1 
as the decimal representation where ti tells the i-th digit from 
the right. The leftmost digit tn is the most significant digit.

4)Now, after representing the given number this way we generate 
the numbers less than the given number and simultaneously 
calculate using DP, if the number satisfy the given property.

We start generating integers having number of digits = 1 and 
then till number of digits = n. Integers having less number of 
digits than n can be analyzed by setting the leftmost digits to
be zero.

5)Convert the given number to a string.
say sn sn-1 .... s1.

6)Declare the string globally to avoid useless recursive calls.

7)Standard digit dp question.

Lets call some positive integer classy if its decimal 
representation contains no more than 3 non-zero digits. 

You are given a segment [𝐿;𝑅]. 
Count the number of classy integers 𝑥 such that 𝐿≤𝑥≤𝑅.


>N: upper limit in number of digits in number.
>M: upper limit of Max value of function G(x)
>2: tight specifies whether we are free to chose any number 
    as the current digit.

int dp[N][M][2];
string s;

int solve(int pos, int cnt, int t)
{
	if (pos == int(s.size()))
	{
		return cnt <= 3;
	}

	if (dp[pos][cnt][t] != -1)
		return dp[pos][cnt][t];

	int lim = t ? s[pos] - '0' : 9;
	int ans = 0;

	for (int i = 0; i <= lim; i++)
	{
		ans += solve(pos + 1, cnt + (i != 0), t & (i == lim));
	}

	return dp[pos][cnt][t] = ans;
}

int main()
{
	cin >> a >> b;

	int i = a.size() - 1;
	while (a[i] == '0')
	{
		a[i] == '9';
		i--;
	}
	a[i]--;

	s = a;
	memset(dp, -1, sizeof(dp));
	int l = solve(0, 0, 1);

	s = b;
	memset(dp, -1, sizeof(dp));
	int r = solve(0, 0, 1);

	cout << r - l;
}
