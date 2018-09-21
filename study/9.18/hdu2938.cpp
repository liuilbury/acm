#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
const int maxn = 3000005;
struct pop
{
    long long min;
    long long max;
} tree[maxn * 4];
long long lazy[maxn * 4];
int n, m;
void build(int node = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        tree[node].max = tree[node].min = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(node << 1, l, mid);
    build((node << 1) + 1, mid + 1, r);
    tree[node].max = std::max(tree[node << 1].max, tree[(node << 1) + 1].max);
    tree[node].min = std::max(tree[node << 1].min, tree[(node << 1) + 1].min);
}
void pushdown(int node)
{
    if (lazy[node])
    {
        lazy[node << 1] += lazy[node];
        lazy[(node << 1) + 1] += lazy[node];
        tree[node << 1].max += lazy[node];
        tree[(node << 1) + 1].max += lazy[node];
        tree[node << 1].min += lazy[node];
        tree[(node << 1) + 1].min += lazy[node];
        lazy[node] = 0;
    }
}
int g_L, g_R;
long long g_Add;
void change(int node = 1, int l = 1, int r = n)
{
    if (g_L <= l && r <= g_R && (tree[node].max < g_Add || tree[node].min > g_Add))
    {
        tree[node].min += g_Add;
        tree[node].max += g_Add; //这个结点对应线段的所有点都加上了g_Add，所以最大值也加g_Add
        lazy[node] += g_Add;     //我们只操作这个结点，而不递归传下去，因为这时我们传下去了也用不到，所以通过lazy保存结点对应线段每个点的增加值
        return;
    }
    int mid = (l + r) / 2;
    int lc = node << 1;
    int rc = (node << 1) + 1;
    //现在要更新子结点了对吧，既然子结点的最大值还没有加上g_Add，那我们怎么知道加了后的值是多少呢？
    pushdown(node); //那就更新它，把lazy记号推下去
    if (g_L <= l && r <= g_R && (tree[node].max == g_Add && tree[node].min == g_Add))
    {
        return;
    }
    if (g_L <= mid)
        change(lc, l, mid);
    if (g_R > mid)
        change(rc, mid + 1, r);
    tree[node].max = std::max(tree[lc].max, tree[rc].max); //记住要回来更新父结点
    tree[node].min = std::min(tree[lc].min, tree[rc].min);
}

//使用g_L和g_R
long long query(int node = 1, int l = 1, int r = n)
{
    if (g_L <= l && r <= g_R)
    {
        return tree[node].max; //注意tree[node]的含义：我们已经保证tree[node]已经更新，所以答案就是tree[node]，不要再加上lazy[node]，它是作用于子结点的
    }
    int mid = (l + r) / 2;
    int lc = node << 1;
    int rc = (node << 1) + 1;
    pushdown(node); //查询时也要更新，以把加上的值记录在内

    long long ans = 0;
    if (g_L <= mid)
        ans = std::max(ans, query(lc, l, mid));
    if (g_R > mid)
        ans = std::max(ans, query(rc, mid + 1, r));
    return ans;
}

int main()
{
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(lazy, 0, sizeof(lazy));
        build();
        while (m--)
        {
            int operation, l, r;
            long long value;
            scanf("%d%d%lld", &l, &r, &value);
            g_L = l;
            g_R = r;
            g_Add = value;
            change();
        }
        for (int i = 1; i <= n; i++)
        {
            g_L = g_R = i;
            if (i == 1)
                printf("%lld", query());
            else
                printf(" %lld", query());
        }
        printf("\n");
    }
    return 0;
}