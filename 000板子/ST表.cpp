#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#define inf 0x7fffffff
using namespace std;
const int MAXN=50010;
int n,q;
int a[MAXN],ST_max[MAXN][16],ST_min[MAXN][16],l,r;//第二维空间要开log2(MAXN)那么大。
void Sparse_Table()
{
    for (int i=1 ;i<=n ;i++)//初始值，区间长度为1的区间最大值和最小值都是a[i]本身。
    {
        ST_max[i][0]=ST_min[i][0]=a[i];
    }
    for (int j=1 ;(1<<j)<=n ;j++)//从2^1开始枚举，直到2^j大于n
    {
        for (int i=1 ;i+(1<<j)-1<=n ;i++)//枚举每个点，合并两个子区间的信息。
        {
            ST_max[i][j]=max(ST_max[i][j-1],ST_max[i+(1<<(j-1))][j-1]);
            ST_min[i][j]=min(ST_min[i][j-1],ST_min[i+(1<<(j-1))][j-1]);
        }
    }
}
int RMQ(int l,int R)
{
    int k;
    for (k=0;(1<<(k+1))<=r-l+1;++k);//k表示不大于查询区间长度最大的2的正整数幂
    int maxnum=max(ST_max[l][k],ST_max[r-(1<<k)+1][k]);
    int minnum=min(ST_min[l][k],ST_min[r-(1<<k)+1][k]);
    return maxnum-minnum;//这道题返回的是极值差，如果需要返回最大值、最小值，请按需要修改
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1 ;i<=n ;i++)
        {
            scanf("%d",&a[i]);
        }
        Sparse_Table();
        int m;
        scanf("%d", &m);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",RMQ(l,r));
        }
    }
    return 0;
}
