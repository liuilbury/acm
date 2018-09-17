long long quickpow(long long a, long long b, long long c)
{
    long long ans = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b >>= 1;
    }
    return ans % c;
}
long long quickmid(long long a, long long b, long long c)
{
    long long ans = 0;
    while (b != 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % c;
        }
        a = (a + a) % c;
        b >>= 1;
    }
    return ans % c;
}