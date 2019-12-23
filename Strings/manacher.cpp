Manacher Algo

1)Finds all sub-palindromes in O(n)
2)Convert given string s to t where t starts and ends with 
deliminaters like ($ and @) and each char of s is seperated 
by another deliminater like #.

string s: abababa

$ # a # b # a # b # a # b # a # @  string t
0 0 1 0 3 0 5 0 7 0 5 0 3 0 1 0 0  p array

3)Construct the p[] array using the following algo 

string manacher(string s)
{
    string t = "$";
    lli n = s.si;
    forz(i, n)
    {
        t += "#";
        t += s[i];
    }
    t+="#@";
    lli len = t.si;
    lli p[len] = {0};
    lli center = 0, right = 0;
    for (int i = 1; i < len-1; i++)
    {
        lli mirror = 2 * center - i;
        if (i < right)
            p[i] = min(p[mirror], right - i);
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            p[i]++;
        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
    }
    lli length=-1,in=-1;
    for(int i=1;i<len;i++)
    {
        if(p[i]>length)
        {
            length=p[i];
            in=i;
        }
    }
    return s.substr((in-1-length)/2,length);
}
