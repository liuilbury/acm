#include <bits/stdc++.h>
using namespace std;
bool check(long long x)
{
    while (x)
    {
        int t = x % 10;
        x /= 10;
        if (t == 7)
            return true;
    }
    return false;
}
int main()
{
    long long a[110] = {0};
    int n;
    int cnt = 0, cnt1 = 0;
    for (long long i = 1;; i++)
    {
        if (i % 7 == 0 || check(i))
        {
            cnt++;
            if (a[cnt] == 0)
            {
                a[cnt] = i - cnt + 1;
            }
            if (cnt == 99)
                break;
        }
        else
        {
            cnt = 0;
        }
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        if(n<=100)
        printf("%lld\n", a[n]);
        else
        {
            int cnt = 7;
            for (int i = 1; i <= 9;i++)
            {
                if(cnt>=n)
                {
                    printf("%d\n", cnt);
                    break;
                }
                else
                {
                    cnt *= 10;
                }
            }
        }
    }
}