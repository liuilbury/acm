#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 1200010
#define INF 0x3f3f3f3f
long long Min[N];
long long Max[N];
long long lazy[N];
bool vis[N];
///向上更新最值
void PushUp(int root)
{
    Min[root] = min(Min[root << 1], Min[(root << 1) + 1]);
    Max[root] = max(Max[root << 1], Max[(root << 1) + 1]);
}
///向下更新最值
void PushDown(int root, int c)
{
    Min[root << 1] = Min[(root << 1) + 1] = lazy[root];
    Max[root << 1] = Max[(root << 1) + 1] = lazy[root];
    vis[root << 1] = vis[(root << 1) + 1] = true;
    lazy[root << 1] = lazy[(root << 1) + 1] = lazy[root];
    vis[root] = false;
}
///建树，根节点为root，区间为（l,r）
void build(int l, int r, int root)
{
    if (l == r)
    {
        //scanf("%d", &Min[root]);
        Max[root] = Min[root];
        return;
    }
    long long m = (l + r) >> 1;
    build(l, m, root << 1);
    build(m + 1, r, (root << 1) + 1);
    PushUp(root);
}
///在（l,r）区间内，根节点为root，求（L,R）区间的最小值
long long getMin(int L, int R, int l, int r, int root)
{
    //  if(vis[root]) return Min[root];
    if (L <= l && R >= r)
        return Min[root];
    if (vis[root])
        PushDown(root, lazy[root]);
    long long m = (l + r) >> 1, ret = INF;
    if (L <= m)
        ret = min(ret, getMin(L, R, l, m, root << 1));
    if (R > m)
        ret = min(ret, getMin(L, R, m + 1, r, (root << 1) + 1));
    return ret;
}
///在（l,r）区间内，根节点为root，求（L,R）区间的最大值
long long getMax(int L, int R, int l, int r, int root)
{
    //if(vis[root]) return Max[root];
    if (L <= l && R >= r)
        return Max[root];
    if (vis[root])
        PushDown(root, lazy[root]);
    long long m = (l + r) >> 1, ret = 0;
    if (L <= m)
        ret = max(ret, getMax(L, R, l, m, root << 1));
    if (R > m)
        ret = max(ret, getMax(L, R, m + 1, r, (root << 1) + 1));
    return ret;
}
///在（l,r）区间内，根节点为root，将（L,R）区间的数更新为 c
void update(int L, int R, int c, int l, int r, int root)
{
    if (L <= l && R >= r)
    {
        Min[root] += c;
        Max[root] += c;
        lazy[root] += c;
        vis[root] = true;
        return;
    }
    if (vis[root])
        PushDown(root, c);
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, l, m, root << 1);
    if (R > m)
        update(L, R, c, m + 1, r, (root << 1) + 1);
    PushUp(root);
}
long long w[300100];
int main()
{
    int n, m, a, b, c, t;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(vis, false, sizeof(vis));
        memset(Min, 0, sizeof(Min));
        memset(Max, 0, sizeof(Max));
        memset(lazy, 0, sizeof(lazy));
        memset(w, 0, sizeof(w));
        build(1, n, 1);
        while (m--)
        {
            scanf("%d %d %d", &a, &b, &c);
            printf("%lld %lld\n", getMax(a, b, 1, n, 1), getMin(a, b, 1, n, 1));
            update(a, b, c, 1, n, 1);
            w[a] += c;
            w[b + 1] -= c;
        }
        long long ans = 0;
        for (int i = 1; i <= n;i++)
        {
            ans += w[i];
            if(i==1)
                printf("%lld", ans);
            else
                printf(" %lld", ans);
        }
        printf("\n");
    }
    return 0;
}
