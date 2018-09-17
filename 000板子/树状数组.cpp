#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=100005;
int a[MAXN],n;
int sum[MAXN];
int lowbit(int x)//lowbit(x)Ҳ��ʾx���λ������������ĳ���
{
    return x&-x;
}
long long q(int x)//��ѯ1-x��ǰ׺��
{
    long long ans=0;//��ѯʱһ�������ߣ�һ�ߺϲ������
    while(x)
    {
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
void change(int x,int num)//��x��������num
{
    while(x<=n)//�޸�ʱһ�������ߣ�һ���޸���;�����ĵ�
    {
        sum[x]+=num;
        //printf("%d", sum[x]);
        x+=lowbit(x);
    }
    return;
}
long long qsum(int l,int r)//��ѯl��r�������
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
