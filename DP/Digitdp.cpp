1)There are many types of problems that ask to count the number of integers ‘x‘ between two integers say ‘a‘ and ‘b‘ such that x satisfies a specific property that can be related to its digits.

2)G(x) tells the number of such integers between 1 to x (inclusively), then the number of such integers between a and b can be given by G(b) – G(a-1).

3)tn tn-1 tn-2 … t2 t1 as the decimal representation where ti tells the i-th digit from the right. The leftmost digit tn is the most significant digit.

4)Now, after representing the given number this way we generate the numbers less than the given number and simultaneously calculate using DP, if the number satisfy the given property. We start generating integers having number of digits = 1 and then till number of digits = n. Integers having less number of digits than n can be analyzed by setting the leftmost digits to be zero.

DP STATE:
lli solve(lli idx,G(x)/*parameters*/,lli tight,vector<lli>num)

NOTE:here num is x;
intialise dp[A][B][2];

A:max(idx)+1
B:max(G)+1
C:2 (since tight is always 0 or 1)

1)idx:
It tells about the index value from right in the given integer.
And from left if vector<lli>num is reversed;

2)tight:
This will tell if the current digits range is restricted or not. If the current digit’s.
range is not restricted then it will span from 0 to 9 (inclusively) else it will span
from 0 to num[idx] (inclusively).

i.e if(tight>0)limit=9;
    else limit=num[idx];

3)G:given parameters;

lli solve(idx,G,tight,vector<lli>num)
{
 if(idx==num.si)
 {
   ??
 }
 if(dp[idx][G][tight]!=-1)
   return dp[idx][G][tight];
STATE RELATION:
//MEMOIZATION IS USED

lli limit=(tight?9:num[idx]);
lli ans=0;
for(int i=0;i<=limit;i++)
{
  //CONDITION due to G(x) make currG;

  lli currtight=tight;
  if(i<num[idx])currtight=1;

  ans+=solve(idx+1,currG,c,num)
  //idx+1 if from left idx else idx-1
}
return dp[idx][G][tight]=ans;
}

lli count(lli x)
{
  vector<lli>num;
  while(x)
  {
    num.pb(x%10);
    x/=10;
  }
  //reverse(all(num));
  memset(dp,-1,sizeof(dp));
  return solve(0,0,0,num);
}

cout<<count(r)-count(l-1)<<endl;
