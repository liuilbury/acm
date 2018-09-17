#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
long long ans, c;
int n, m, q, qs, a, b;
/*���ӿ�ʼ�ĵط�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
const int MAXN = 200005;
long long A[MAXN];
struct tnode
{
    long long sum, lazy; //����߶��������������������޸�
    int l, r;
};
struct Segment_Tree
{
    tnode t[4 * MAXN];
    void pushdown(int root) //�Ʊ��
    {
        if (t[root].lazy != 0)
        {
            t[root].sum += t[root].lazy * (t[root].r - t[root].l + 1); //��Ҫ�޸�
            if (t[root].l != t[root].r)
            {
                int ch = root << 1;
                t[ch].lazy += t[root].lazy;
                t[ch + 1].lazy += t[root].lazy;
            }
            t[root].lazy = 0;
        }
    }
    void updata(int root) //���º���
    {
        int ch = root << 1;
        pushdown(ch);
        pushdown(ch + 1);
        t[root].sum = t[ch].sum + t[ch + 1].sum; //��Ҫ�޸�
    }
    void buildt(int root, int l, int r) //�ݹ齨��
    {
        t[root].l = l;
        t[root].r = r;
        if (l != r)
        {
            int mid = (l + r) >> 1;
            int ch = root << 1;
            buildt(ch, l, mid);
            buildt(ch + 1, mid + 1, r);
            updata(root);
        }
        else
            t[root].sum = A[l]; //��Ҫ�޸�
    }
    void change(int root, int l, int r, int n) //�ڸ�Ϊroot�������в���l��r�����䣬��������n��
    {
        if (l == t[root].l && r == t[root].r)
        {
            t[root].lazy += n-t[root].sum;
            pushdown(root);
            return;
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)
            change(ch, l, r, n);
        else if (l > mid)
            change(ch + 1, l, r, n);
        else
        {
            change(ch, l, mid, n);
            change(ch + 1, mid + 1, r, n);
        }
        updata(root);
    }
    long long sum(int root, int l, int r) //�ڸ�Ϊroot�������в���l��r�����䲢�Ҳ�ѯ��
    {
        pushdown(root);
        if (t[root].l == l && t[root].r == r)
        {
            return t[root].sum; //��Ҫ�޸�
        }
        int mid = (t[root].l + t[root].r) >> 1;
        int ch = root << 1;
        if (r <= mid)
            return sum(ch, l, r); //��Ҫ�޸�
        else if (l > mid)
            return sum(ch + 1, l, r); //��Ҫ�޸�
        else
            return sum(ch, l, mid) ^ sum(ch + 1, mid + 1, r); //��Ҫ�޸�
    }
};
/*���ӽ����ĵط�~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Segment_Tree ST;
int main()
{
    int s, e;

    while (scanf("%d %d", &n,&m) != EOF)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &A[i]);
        }
        ST.buildt(1, 1, n);
        int last;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d %d %d",&x,&y,&e);
            ST.change(1, x, y, -e);
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                printf("%lld", ST.sum(1, i, i));
            else
                printf(" %lld",ST.sum(1, i, i));
        }
        printf("\n");
    }
    return 0;
}
