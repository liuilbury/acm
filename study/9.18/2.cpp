#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define N 120
#define INF 0x3f3f3f3f
bool vis[N];
struct node
{
    int l, r;
    int Max;
    int Min;
    int lazy;
} no[N];
///向上更新最值
void PushUp(int root)
{
    no[root].Min = min(no[root << 1].Min, no[(root << 1) + 1].Min);
    no[root].Max = max(no[root << 1].Max, no[(root << 1) + 1].Max);
}
///向下更新最值
void PushDown(int root, int c)
{
    no[root << 1].Min = no[(root << 1) + 1].Min += c;
    no[root << 1].Max = no[(root << 1) + 1].Max += c;
    vis[root << 1] = vis[(root << 1) + 1] = true;
    no[root << 1].lazy = no[(root << 1) + 1].lazy += c;
    vis[root] = false;
}
///建树，根节点为root，区间为（l,r）
void build(int l, int r, int root)
{
    if (l == r)
    {
        //scanf("%d", &no[root]);
        no[root].Max = no[root].Min = 0;
        no[root].l = l;
        no[root].r = r;
        return;
    }
    int m = (l + r) >> 1;
    no[root].l = l;
    no[root].r = r;
    build(l, m, root << 1);
    build(m + 1, r, (root << 1) + 1);
    PushUp(root);
}
///在（l,r）区间内，根节点为root，求（L,R）区间的最小值
int getMin(int L, int R, int l, int r, int root)
{
    //  if(vis[root]) return no[root];
    if (L <= l && R >= r)
        return no[root].Min;
    if (vis[root])
        PushDown(root, no[root].lazy);
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
    //if(vis[root]) return no[root];
    if (L <= l && R >= r)
        return no[root].Max;
    if (vis[root])
        PushDown(root, no[root].lazy);
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
    if (L <= l && R >= r && (no[root].Min > c || no[root].Max < c))
    {
        no[root].Min += c;
        no[root].Max += c;
        no[root].lazy += c;
        vis[root] = true;
        return;
    }
    if (vis[root])
        PushDown(root, c);
    if (L <= l && R >= r && (no[root].Min == no[root].Max && no[root].Max == c))
    {
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
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
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
        printf("%2d ", getMin(i, i, 1, n, 1));
    }
    printf("\n");
    return 0;
}
