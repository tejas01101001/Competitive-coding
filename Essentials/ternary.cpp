lli ternary(int lo, int hi)
{
    //fucntion f should be unimodal
    //i.e convex or concave
    while (lo + 3 <= hi)
    {
        int m1 = lo + (hi - lo) / 3;
        int m2 = hi - (hi - lo) / 3;
        if (func(m1) <= func(m2))
            hi = m2;
        else
            lo = m1;
    }
    lli ans = func(lo);
    for (int i = lo + 1; i <= hi; i++)
        ans = min(ans, func(i));
    return ans;
}