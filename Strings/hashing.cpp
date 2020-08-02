Hashing

1)hash(s)=∑s[i]⋅p^i(mod m) i=[0,n-1]
2)if the input is composed of only lowercase letters of English alphabet, p=31 is a good choice. If the input may contain both uppercase and lowercase letters, then p=53 is a possible choice.
3)Resonable to take p as prime even m prime.
4)m should be large
5)m=1e9+9;
6)Converting a→0 is not a good idea, because then the hashes of the strings a, aa, aaa, … all evaluate to 0.Hence convert a to 1.

vector<lli>pro(n),h(n+1,0);
pro[0]=1;
for(int i=1;i<n;i++)
  pro[i]=(pro[i-1]*p)%m;
forz(i,n)
  h[i+1]=(h[i]+(s[i]-'a'+1)*pro[i])%m;

h[i]:hash of ith prefix of the string
hash(s[i…j])*p^i=hash(s[0…j])−hash(s[0…i−1]) (mod m);
i.e h[i,j]*p^i=h[j]-h[i-1];

7)For every substring length l we construct an array of hashes of all substrings of length l multiplied by the same power of p.

for(int l=n-1;l>=1;l--)
{
lli pre,cur,suf;
pre=(h[l]*pro[n-1])%m;
suf=(h[n]+m-h[n-l])%m;
suf=(suf*pro[l-1])%m;
  for(int i=1;i<=n-l-1;i++)
  {
  cur=(h[i+l]+m-h[i])%m;
  cur=(cur*pro[n-i-1])%m;
  }
}

substrings of length l
for h[i...j]=h[j]-h[i-1];
multiply it by pro[n-i-2];
in short :
for h[a]-h[b];
multiply it by pro[n-1-b];

8)There is a really easy trick to get better probabilities. We can just compute two different hashes for each string (by using two different p, and/or different m, and compare these pairs instead. If m is about 1e9 for each of the two hash functions, than this is more or less equivalent as having one hash function with m≈10e18. When comparing 1e6 strings with each other, the probability that at least one collision happens is now reduced to ≈1e(-6).

9)sometimes take p as 13331 and remove the mod p should be lli
a)Strings x and y are compared with each other. The probability of
a collision is 1/m assuming that all hash values are equally probable
m ideal:1e9
b)A string x is compared with strings y1, y2, . . . , yn.
m ideal:1e12
c)All pairs of strings x1, x2, . . . , xn are compared with each other.
m ideal:1e18(remove mod)
