lli tau(lli num)
{
    lli count = 0;
    lli pp = 1;
    while (num % 2 == 0)
    {
        count++;
        num /= 2;
    }
    pp *= (count + 1);
    for (lli i = 3; i <= sqrt(num); i += 2)
    {
        count = 0;
        while (num % i == 0)
        {
            count++;
            num /= i;
        }
        pp *= (count + 1);
    }
    if (num > 2)
    {
        pp *= 2;
    }
    return pp;
}