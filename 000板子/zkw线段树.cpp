#include <cctype>
#include <cstdio>
#include <cstring>
#define N ((131072 << 1) + 10) //表示节点个数->不小于区间长度+2的最小2的正整数次幂*2+10
typedef long long LL;
inline int getc()
{
    static const int L = 1 << 15;
    static char buf[L], *S = buf, *T = buf;
    if (S == T)
    {
        T = (S = buf) + fread(buf, 1, L, stdin);
        if (S == T)
            return EOF;
    }
    return *S++;
}
inline int getint()
{
    static char c;
    while (!isdigit(c = getc()) && c != '-')
        ;
    bool sign = (c == '-');
    int tmp = sign ? 0 : c - '0';
    while (isdigit(c = getc()))
        tmp = (tmp << 1) + (tmp << 3) + c - '0';
    return sign ? -tmp : tmp;
}
inline char getch()
{
    char c;
    while ((c = getc()) != 'Q' && c != 'C')
        ;
    return c;
}
int M;                      //底层的节点数
int dl[N], dr[N];           //节点的左右端点
LL sum[N];                  //节点的区间和
LL add[N];                  //节点的区间加上一个数的标记
#define l(x) (x << 1)       //x的左儿子，利用堆的性质
#define r(x) ((x << 1) | 1) //x的右儿子，利用堆的性质
void pushdown(int x)
{ //下传标记
    if (add[x] && x < M)
    { //如果是叶子节点，显然不用下传标记（别忘了）
        add[l(x)] += add[x];
        sum[l(x)] += add[x] * (dr[l(x)] - dl[l(x)] + 1);
        add[r(x)] += add[x];
        sum[r(x)] += add[x] * (dr[r(x)] - dl[r(x)] + 1);
        add[x] = 0;
    }
}
int stack[20], top; //栈
void upd(int x)
{ //下传x至根节点路径上节点的标记（自上而下，用栈实现）
    top = 0;
    int tmp = x;
    for (; tmp; tmp >>= 1)
        stack[++top] = tmp;
    while (top--)
        pushdown(stack[top]);
}
LL query(int tl, int tr)
{ //求和
    LL res = 0;
    int insl = 0, insr = 0; //两侧第一个有用节点
    for (tl = tl + M - 1, tr = tr + M + 1; tl ^ tr ^ 1; tl >>= 1, tr >>= 1)
    {
        if (~tl & 1)
        {
            if (!insl)
                upd(insl = tl ^ 1);
            res += sum[tl ^ 1];
        }
        if (tr & 1)
        {
            if (!insr)
                upd(insr = tl ^ 1);
            res += sum[tr ^ 1];
        }
    }
    return res;
}
void modify(int tl, int tr, int val)
{ //修改
    int insl = 0, insr = 0;
    for (tl = tl + M - 1, tr = tr + M + 1; tl ^ tr ^ 1; tl >>= 1, tr >>= 1)
    {
        if (~tl & 1)
        {
            if (!insl)
                upd(insl = tl ^ 1);
            add[tl ^ 1] += val;
            sum[tl ^ 1] += (LL)val * (dr[tl ^ 1] - dl[tl ^ 1] + 1);
        }
        if (tr & 1)
        {
            if (!insr)
                upd(insr = tr ^ 1);
            add[tr ^ 1] += val;
            sum[tr ^ 1] += (LL)val * (dr[tr ^ 1] - dl[tr ^ 1] + 1);
        }
    }
    for (insl = insl >> 1; insl; insl >>= 1) //一路update
        sum[insl] = sum[l(insl)] + sum[r(insl)];
    for (insr = insr >> 1; insr; insr >>= 1)
        sum[insr] = sum[l(insr)] + sum[r(insr)];
}
inline void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    //freopen("tt.in" , "r" , stdin);
    int n, ask;
    n = getint();
    ask = getint();
    int i;
    for (M = 1; M < (n + 2); M <<= 1)
        ;
    for (i = 1; i <= n; ++i)
        sum[M + i] = getint(), dl[M + i] = dr[M + i] = i; //建树
    for (i = M - 1; i >= 1; --i)
    { //预处理节点左右端点
        sum[i] = sum[l(i)] + sum[r(i)];
        dl[i] = dl[l(i)];
        dr[i] = dr[r(i)];
    }
    char s;
    int a, b, x;
    while (ask--)
    {
        s = getch();
        if (s == 'Q')
        {
            a = getint();
            b = getint();
            if (a > b)
                swap(a, b);
            printf("%lld\n", query(a, b));
        }
        else
        {
            a = getint();
            b = getint();
            x = getint();
            if (a > b)
                swap(a, b);
            modify(a, b, x);
        }
    }
    return 0;
}