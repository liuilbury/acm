#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
int T, m, k;
long long a[MAXN], p[MAXN], d[MAXN], c[MAXN], pp[25][25];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &m, &k);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%lld %lld", &a[i], &p[i]);
        }
        for (int i = 1; i <= k; ++i)
        {
            scanf("%lld %lld", &c[i], &d[i]);
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                pp[i][j] = (d[j] * (100 - p[i])) / 100 + !!((d[j] * (100 - p[i])) % 100);
            }
        }
        long long ans = 0;
        for (int j = 1; j <= k; ++j)
        {
            ans += d[j] * c[j];
        }
        ans = ans / 10 + !!(ans % 10);
        for (int i = 1; i <= m; ++i)
        {
            long long need = 0;
            for (int j = 1; j <= k; ++j)
            {
                need += pp[i][j] * c[j];
            }
            need = max(a[i], need);
            ans = min(ans, need / 10 + !!(need % 10));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
