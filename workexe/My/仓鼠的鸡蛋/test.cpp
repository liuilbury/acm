#include <bits/stdc++.h>
using namespace std;
#define N 1200010
#define INF 0x3f3f3f3f
long long Max[N];
int vis[N];
int n, t, k;
int T;
void build(int l, int r, int root)
{
    if (l == r)
    {
        Max[root] = t;
        return;
    }
    long long m = (l + r) >> 1;
    build(l, m, root << 1);
    build(m + 1, r, (root << 1) + 1);
    Max[root] = max(Max[root << 1], Max[(root << 1) + 1]);
}
long long w;
void check(int l, int r, int root)
{
    if (l == r)
    {
        printf("%d\n", l);
        vis[l]++;
        if (vis[l] == k)
        {
            Max[root] = -1;
        }
        else
            Max[root] -= w;
        return;
    }
    if (Max[root * 2] >= w)
    {
        check(l, (l + r) >> 1, root << 1);
        Max[root] = max(Max[root << 1], Max[(root << 1) + 1]);
    }
    else
    {
        check(((l + r) >> 1) + 1, r, (root << 1) + 1);
        Max[root] = max(Max[root << 1], Max[(root << 1) + 1]);
    }
}
int main()
{
    //freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &n, &t, &k);
        memset(vis, 0, sizeof(vis));
        build(1, n, 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &w);
            if (Max[1] < w)
            {
                printf("-1\n");
                continue;
            }
            check(1, n, 1);
        }
    }
    return 0;
}