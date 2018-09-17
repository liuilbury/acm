#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=100005;
int a[MAXN],n;
int sum[MAXN];
int lowbit(int x)//lowbit(x)也表示x这个位置所储存区间的长度
{
    return x&-x;
}
long long q(int x)//查询1-x的前缀和
{
    long long ans=0;//查询时一边往左走，一边合并区间和
    while(x)
    {
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
void change(int x,int num)//给x这个点加上num
{
    while(x<=n)//修改时一边往右走，一边修改沿途遇到的点
    {
        sum[x]+=num;
        //printf("%d", sum[x]);
        x+=lowbit(x);
    }
    return;
}
long long qsum(int l,int r)//查询l到r的区间和
{
    return q(r)-q(l-1);
}
int main()
{
    int x;
    n = 4;
    for (int i = 1; i <= 4;i++)
    {
        scanf("%d", &x);
        change(i, x);
    }
    for (int i = 1; i <= 4;i++)
        printf("%lld\n", sum[i]);
        printf("%lld\n", qsum(1, 4));
    system("pause");
    return 0;
}
