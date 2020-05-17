Dynamic Programming

1) Overlapping Subproblems:
So Dynamic Programming is not useful when there are no common 
(overlapping) subproblems because there is no point storing 
the solutions if they are not needed again.

a) Memoization (Top Down):
The memoized program for a problem is similar to the recursive
version with a small modification that it looks into a lookup 
table before computing solutions. We initialize a lookup array
with all initial values as NIL. Whenever we need the solution
to a subproblem, we first look into the lookup table. 
If the precomputed value is there then we return that value, 
otherwise, we calculate the value and put the result in the 
lookup table so that it can be reused later.

b) Tabulation (Bottom Up): 
The tabulated program for a given problem builds a table in bottom 
up fashion and returns the last entry from table.

2) Optimal Substructure: A given problems has Optimal Substructure 
Property if optimal solution of the given problem can be obtained 
by using optimal solutions of its subproblems.

3)Used for:
a)count something,often no of ways
b)min or max some value
c)check if something is possible

for b and c we can also think of some better greedy approach.

4)TRICKS AND PROBLEMS:

1)Climbing Stairs:
1 or 2 steps at a time and atmost k jumps:
>with no limit on jumps
dp[i]=dp[i-1]+dp[i-2];
>with limit:
dp[i][k]=dp[i-1][k-1]+dp[i-2][k-1];
ans will be
∑dp[n][j] for j=[0,k]

2)Minimum path sum:
dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
>with no two consecutive down steps:
dp[row][col][2]

>>PUSH OR FORWARD DP IS BETTER:
>>Minimise something put INF everywhere except the first one.
>>Think what is important so far and make the dimmensions.
>>AVOID DOUBLE COUNTING

3)Combination Sum:
Given the target value N and an array of allowed numbers,
count the ways to write N as the sum of those numbers.
nums:allowed numbers:

dp[i]:no of ways to get the sum as i 

Backward DP
dp[0]=1;
forz(i,n)
 for(x in nums)dp[i]+=dp[i-x];

Forward DP
dp[0]=1;
forz(i,n-1)
  for(x in nums)dp[i+x]+=dp[i];

4)Coin change(min)
You are given denominations of coins and the target value N.
What is the minimum possible number of coins:
dp[i]:min no of coins to get sum as i 

dp[0]=0
dp[1..N]=INF;
for i=[1....N]:
  for x in coins:
    dp[i]=min(dp[i],dp[i-x]+1);

5)Coin change(ways)
Given denominations of coins and the target amount N.
What is the number of ways to make up amount N:

Order of coins doesnt matter
k:no of denominations:
dp[n][k]
dp[s][last]
last is the last index of the coin used
If used coins are 0 1 1 and 2 you can say that last coin Used
is 4 if you aint going to take smaller coins
index are given:

(17,2)->(17+num[2],2)
|
(17,3)->(17+num[3],3)
|
(17,4)

ans is ∑dp[n][j] for j=[0,k-1]

6)LCS:Longest common subseq
dp[i][j]:i is the length of prefix of string s
         j is the lenght of the prefix of string t 
         dp[i][j] gives the LCS of s and t.

dp[n+1][m+1]
if(i==0||j==0)dp[i][j]=0;
if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
ans=dp[n][m];
n:length of s;
m:lenght of t;

7)Edit distance:
Given two strings s,t find min number of edits
1)Insert
2)Remove
3)Replace

dp[n+1][m+1]
first:no of elements in first string
second:no of elements in second string

dp[0][j]=j;
dp[i][0]=i;

if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1];
else dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                     insert     remove     replace
ans=dp[n][m]

8)Cutting a Rod
Given a rod of length n inches and an array of prices that
contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod
and selling the pieces.

int best=-1;
cost[n+1];
cost[0]=0;
cost[i]:best possible cost for length i

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=i;j++)
		best=max(best,cost[j]+dp[i-j]);

	dp[i]=best;
}

9)No of distinct subseq of length n:
lli a[n+1][n+1]={0};
a[i][j]:
first dimmension for length of subseq
second for length of prefix of string
forz(i,n+1)
{
  a[i][0]=0;//no chars to choose from
  a[0][i]=1;//empty subseq
}
for(int i=1;i<=n;i++)
{
   vector<lli>l(256,-1);
   //256 no of chars
   for(int j=1;j<=n;j++)
   {
	   a[i][j]=a[i][j-1]+a[i-1][j-1];//length either i or i-1
	   if(l[s[j-1]]!=-1)
	   a[i][j]-=a[i-1][l[s[j-1]]];//subtract repetitions
	   l[s[j-1]]=(j-1);//mark last occurance of char
   }
}

ans=a[x][n];
where x is the length of subseq required

10)Binomial coefficent:
C[n][k]=C[n-1][k-1]+C[n-1][k];
C[n][0]=C[n][n]=1;

11)LPS:longest palindrome subseq
dp[n][n]:
First dimmension for l,
and second for r;
dp[i][j]:lps of [i,.....,j]
hence ans=dp[0][n-1];

forz(i,n)
dp[i][i]=1;

length of substing be l:
int l,i,j;
for(l=2;l<=n;l++)
{
	for(int i=0;i<n-l+1;i++)
	{
		 j=i+l-1;
         //l=j-i+1
		 if(s[i]==s[j]&&l==2)dp[i][j]=2;
		 else if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
		 else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
    }
}

12)Knapsack Problem:
Given weights and values of n items, 
put these items in a knapsack of capacity w to get the maximum 
total value in the knapsack.

>>Method 1:O(nw)

1)Backward DP
dp[n+1][w+1];
wt[n+1],val[n+1];
ans is dp[n][w];

First dimension for first i objects
second for size of sack

for(int i=1;i<=n;i++)
{
	for(int j=0;j<=w;j++)
	{
		if(i==0||j==0)dp[i][j]=0;
		else if(wt[i]<=j)
		{
			dp[i][j]=max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
		}
		else dp[i][j]=dp[i-1][j];
		}
}

2)Forward DP:O(nw)
dp[w+1];
for(int i=0;i<n;i++)
{
	lli wt,v;
	cin>>wt>>v;
	for(int rem=w-wt,rem>=0;rem--)
	{
		dp[rem+wt]=max(dp[rem+wt],dp[rem]+v);
	}
}
ans=maxe(dp,dp+w+1);

>>Alternative:O(nv)

lli wt[n+1],val[n+1];
 lli s=0;
 for(int i=1;i<=n;i++)
 {
   cin>>wt[i]>>val[i];
   s+=val[i];
 }
 lli INF=1e18+5;
 vector<lli>dp(s+1,INF);
 dp[0]=0;
 //dp[i] the min total weight of items with total value i
 for(int i=1;i<=n;i++)
 {
   for(int j=s;j>=val[i];j--)
   {
     dp[j]=min(dp[j],dp[j-val[i]]+wt[i]);
   }
 }
 lli ans=0;
 forz(i,s+1)
 {
   if(dp[i]<=w){
     ans=max(ans,lli(i));}
 }

13)
