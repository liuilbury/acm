/*  主席树求区间第K大模板：
 *      模板特殊说明：
 *          每棵树是维护从1开始到cnt的下标信息
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 100000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
int T, n, m, tot, a[MAXN], b[MAXN], cnt;
//T为输入cas组数，n为原数列数组个数，m为询问个数，tot为建树时新节点
//a为原数列，b为用来离散化的数列，其unique后元素个数为cnt
struct N
{
    int ls, rs, w;
} tree[30 * MAXN];
//ls为左儿子节点下标，rs为右儿子节点下标，w为此区间内元素数量
int roots[MAXN];
//roots记录每棵树的根节点下标
int build_tree(int l, int r)
{ //先建造一棵空树
    int newnode = tot++;
    tree[newnode].w = 0;
    if (l != r)
    {
        int mid = (l + r) / 2;
        tree[newnode].ls = build_tree(l, mid);
        tree[newnode].rs = build_tree(mid + 1, r);
    }
    return newnode;
}
int updata(int rt, int pos, int val)
{ //rt为根节点，在pos位置上加val的值
    int newnode = tot++, tmp = newnode;
    tree[newnode].w = tree[rt].w + val;
    int l = 1, r = cnt;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            tree[newnode].ls = tot++;
            tree[newnode].rs = tree[rt].rs;
            newnode = tree[newnode].ls;
            rt = tree[rt].ls;
            r = mid;
        }
        else
        {
            tree[newnode].ls = tree[rt].ls;
            tree[newnode].rs = tot++;
            newnode = tree[newnode].rs;
            rt = tree[rt].rs;
            l = mid + 1;
        }
        tree[newnode].w = tree[rt].w + val;
    }
    return tmp;
}
int query(int rt1, int rt2, int k)
{ //询问根节点分别为rt1，rt2两棵树之间第k大的值
    int l = 1, r = cnt;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int tmp = tree[tree[rt2].ls].w - tree[tree[rt1].ls].w;
        if (tmp >= k)
        {
            rt1 = tree[rt1].ls;
            rt2 = tree[rt2].ls;
            r = mid;
        }
        else
        {
            k -= tmp;
            rt1 = tree[rt1].rs;
            rt2 = tree[rt2].rs;
            l = mid + 1;
        }
    }
    return l;
}
int main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    { //读入数据组数
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[i - 1] = a[i];
        }
        sort(b, b + n);
        cnt = unique(b, b + n) - b; //离散化
        tot = 0;
        roots[0] = build_tree(1, cnt);
        for (int i = 1; i <= n; i++)
        {
            int tmp = (int)(lower_bound(b, b + cnt, a[i]) - b) + 1;
            roots[i] = updata(roots[i - 1], tmp, 1); //在上一次的基础上建树
        }
        int l, r, k;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &l, &r, &k); //读入求l和r区间第k大的数
            int tmp = query(roots[l - 1], roots[r], k);
            printf("%d\n", b[tmp - 1]);
        }
    }
    return 0;
}
