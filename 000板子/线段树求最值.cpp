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
            update(a, b, c, 1, n, 1);
            for (int i = 1; i <= n; i++)
            {
                printf("%2d ", getMin(i, i, 1, n, 1));
            }
            w[a] += c;
            w[b + 1] -= c;
        }
        long long ans = 0;

    }
    return 0;
}

//问最小值

//Q a b 询问(a,b)中最小值

//C a b 将a点值改为b

#include <bits/stdc++.h>

using namespace std;

#define maxn 200005



int min(int a, int b)

{

	return a>b ? b : a;

}

int tree[4 * maxn];



void pushup(int i)

{

	tree[i] = min(tree[i << 1], tree[i << 1 | 1]);

}



void build(int i, int l, int r)

{

	if (l == r)

	{

		scanf("%lld", &tree[i]);

		return;

	}

	int mid = (l + r) / 2;

	build(i << 1, l, mid);

	build(i << 1 | 1, mid + 1, r);

	pushup(i);

}



void update(int i, int l, int r, int x, int val)

{

	if (l == r)///l==x²»±ØÒª

	{

		tree[i] = val;

		return;

	}

	int mid = (l + r) / 2;

	if (x <= mid) update(i << 1, l, mid, x, val);

	else update(i << 1 | 1, mid + 1, r, x, val);

	pushup(i);

}



int query(int i, int l, int r, int x, int y)

{

	if (x <= l && r <= y)

		return tree[i];

	int minn = 9999999;

	int mid = (l + r) / 2;

	if (x <= mid) minn = min(minn, query(i << 1, l, mid, x, y));

	if (y>mid) minn = min(minn, query(i << 1 | 1, mid + 1, r, x, y));

	return minn;

}



int main()

{

	int n, m;

	int b, c;

	char a;

	while (scanf("%d%d", &n, &m) != -1)

	{

		build(1, 1, n);

		while (m--)

		{

			scanf(" %c%d%d", &a, &b, &c);

			if (a == 'Q')

				printf("%d\n", query(1, 1, n, b, c));

			else

				update(1, 1, n, b, c);

		}

	}

	return 0;

}
