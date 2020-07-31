Z Algorithm

1)Thus, z[k] = p tells us that s[0. . . p−1] equals s[k. . . k+ p−1].
2)At each position k, we first check the value of z[k−x]. If k+z[k−x] < y,
we know that z[k] = z[k−x]. However, if k+z[k−x] ≥ y, s[0. . . y−k] equals
s[k. . . y], and to determine the value of z[k] we need to compare the 
substrings character by character.

lli n=s.si;
vector<lli>z(n);
lli x=0,y=0;
for(int i=1;i<n;i++)
{
  z[i]=max(0LL,min(z[i-x],y-i+1));
  while(i+z[i]<n&&s[z[i]]==s[i+z[i]])
  {
    x=i;
    y=i+z[i];
    z[i]++;
  }
}

3)Search the substring
The Z-array of p#s tells us the positions where p occurs in s, 
because such positions contain the length of p.

4)String compression
Given a string s of length n. Find its shortest "compressed" representation, 
that is: find a string t of shortest length such that s can be represented 
as a concatenation of one or more copies of t.

A solution is: compute the Z-function of s, 
loop through all i such that i divides n. 
Stop at the first i such that i+z[i]=n. 
Then, the string s can be compressed to the length i.

5)Number of distinct substrings in a string
