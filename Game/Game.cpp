Game Theory
1)Nim-Sum: The cumulative XOR value of the number of coins/stones in each piles/heaps at any point of the game is called Nim-Sum at that point.
2)optimal strategy for each player is to make the Nim Sum for his opponent zero in each of their turn
3)MEX:Minimum excludant’ a.k.a ‘Mex’ of a set of numbers is the smallest non-negative number not present in the set.
eg:mex({0,1,4,7,12})=2
4)The Grundy Number/ nimber is equal to 0 for a game that is lost immediately by the first player, and is equal to Mex of the nimbers of all possible next positions for any other game.

lli mex(unordered_set<lli>s)
{
  lli Mex=0;
  while(s.find(Mex)!=s.end())Mex++;
  return Mex;
}

lli grundy(lli n)
{
  //if only 1,2,3 stones can be removed from a pile
  for(int i=0;i<=3;i++)
    if(n==i)return i;

  if(g[n]!=-1)
   return(g[n]);

  unordered_set<lli>s;
  for(int i=1;i<=3;i++)s.insert(grundy(n-i,g));
  g[n]=mex(s);
  return g[n];
}

int main()
{
  lli g[n+1];
  memset(g,-1,sizeof(g));
  return 0;
}

5)Sprague-Grundy Theorem
a)Break the composite game into sub-games.
b)Then for each sub-game, calculate the Grundy Number at that position.
c)Then calculate the XOR of all the calculated Grundy Numbers.
d)If the XOR value is non-zero, then the player who is going to make the turn (First Player) will win else he is destined to lose, no matter what.
