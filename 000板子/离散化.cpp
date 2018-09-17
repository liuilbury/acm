#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct discretization_node//num表示数值，ki表示在原数组中的下标
{
    int num;
    int ki;
}disc[MAXN];
bool cmp(discretization_node x,discretization_node y)
{
    return x.num<y.num;
}
void discretization(int a[],int n,discretization_node disc[])//原数组，长度，辅助数组
{
    for(int i=1;i<=n;++i)//离散化信息初始化
    {
        disc[i].num=a[i];
        disc[i].ki=i;
    }
    sort(disc+1,disc+1+n,cmp);//排序
    int cnt=0,per;//cnt现在处理到第几大的数了,per:前驱
    for(int i=1;i<=n;++i)
    {
        if(i==1||a[disc[i].ki]!=per)++cnt;//如果这个数和之前的是不同的数字就计数++
        per=a[disc[i].ki];//更新前驱
        a[disc[i].ki]=cnt;//再把cnt填回原数组，就做好了。
    }
    return;
}
int a[MAXN],n;
int main()
{
    return 0;
}
