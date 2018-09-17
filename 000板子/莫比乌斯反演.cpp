#include <cmath>
#include <cstdio>
#include <iostream>
#define N 105005
#define inf 0x7fffffff
using namespace std;
typedef long long ll;
bool not_prime[N];
int prime[N];
ll sum[N];
int mu[N];
int tot;
void Mu(int n)
{
    int i, j;
    mu[1] = 1;
    for (i = 2; i <= n; i++)
    {
        if (!not_prime[i])
        {
            prime[++tot] = i;
            mu[i] = -1;
        }
        for (j = 1; prime[j] * i <= n; j++)
        {
            not_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                mu[prime[j] * i] = 0;
                break;
            }
            mu[prime[j] * i] = -mu[i];
        }
    }
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + mu[i];
}
ll ans(int n, int m)
{
    if (n > m)
        swap(n, m);
    ll last, i, re = 0;
    for (i = 1; i <= n; i = last + 1)
    {
        last = min(n / (n / i), m / (m / i));
        re += (n / i) * (m / i) * (sum[last] - sum[i - 1]);
    }
    return re;
}
int main()
{
    Mu(N);
    int T;
    int a, b, c, d, k;
    scanf("%d", &T);
    int cnt = 1;
    while (T--)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if (k == 0)
        {
            printf("Case %d: 0\n",cnt++);
            continue;
        }
        else
        {
            a--;
            c--;
            a /= k;
            b /= k;
            c /= k;
            d /= k;
            ll Ans = ans(b, d) - ans(a, d) - ans(b, c) + ans(a, c);
            a = max(a, c);
            b = min(b, d);
            ll ans1 = ans(b, b) - ans(a+1, a+1);
            printf("Case %d: %lld\n", cnt++, Ans - ans1 / 2);
        }
    }
    return 0;
}