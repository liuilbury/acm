#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 1200000
#define INF 0x3f3f3f3f
int Min[N];
int Max[N];
int lazy[N];
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
        Max[root] = Min[root] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, root << 1);
    build(m + 1, r, (root << 1) + 1);
    PushUp(root);
}
///在（l,r）区间内，根节点为root，求（L,R）区间的最小值
int getMin(int L, int R, int l, int r, int root)
{
    //  if(vis[root]) return Min[root];
    if (L <= l && R >= r)
        return Min[root];
    if (vis[root])
        PushDown(root, lazy[root]);
    int m = (l + r) >> 1, ret = INF;
    if (L <= m)
        ret = min(ret, getMin(L, R, l, m, root << 1));
    if (R > m)
        ret = min(ret, getMin(L, R, m + 1, r, (root << 1) + 1));
    return ret;
}
///在（l,r）区间内，根节点为root，求（L,R）区间的最大值
int getMax(int L, int R, int l, int r, int root)
{
    //if(vis[root]) return Max[root];
    if (L <= l && R >= r)
        return Max[root];
    if (vis[root])
        PushDown(root, lazy[root]);
    int m = (l + r) >> 1, ret = 0;
    if (L <= m)
        ret = max(ret, getMax(L, R, l, m, root << 1));
    if (R > m)
        ret = max(ret, getMax(L, R, m + 1, r, (root << 1) + 1));
    return ret;
}
///在（l,r）区间内，根节点为root，将（L,R）区间的数更新为 c
void update(int L, int R, int c, int l, int r, int root)
{
    if (L <= l && R >= r && (Min[root] > c || Max[root] < c))
    {
        Min[root] += 2*c;
        Max[root] += 2*c;
        lazy[root] += 2*c;
        vis[root] = true;
        return;
    }
    if (vis[root])
        PushDown(root, c);
    if (L <= l && R >= r && (Min[root] == Max[root]))
    {
        Min[root] += c;
        Max[root] += c;
        lazy[root] += c;
        vis[root] = true;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, c, l, m, root << 1);
    if (R > m)
        update(L, R, c, m + 1, r, (root << 1) + 1);
    PushUp(root);
}
int main()
{
    //freopen("test/2.in", "r", stdin);
    //freopen("test/2.out", "w", stdout);
    int n, m, a, b, c, t;
    scanf("%d %d", &n, &m);
    build(1, n, 1);
    while (m--)
    {
        scanf("%d %d %d", &a, &b, &c);
        update(a, b, c, 1, n, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", getMax(i, i, 1, n, 1));
    }
    return 0;
}
