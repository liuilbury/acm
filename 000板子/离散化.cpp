#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct discretization_node//num��ʾ��ֵ��ki��ʾ��ԭ�����е��±�
{
    int num;
    int ki;
}disc[MAXN];
bool cmp(discretization_node x,discretization_node y)
{
    return x.num<y.num;
}
void discretization(int a[],int n,discretization_node disc[])//ԭ���飬���ȣ���������
{
    for(int i=1;i<=n;++i)//��ɢ����Ϣ��ʼ��
    {
        disc[i].num=a[i];
        disc[i].ki=i;
    }
    sort(disc+1,disc+1+n,cmp);//����
    int cnt=0,per;//cnt���ڴ����ڼ��������,per:ǰ��
    for(int i=1;i<=n;++i)
    {
        if(i==1||a[disc[i].ki]!=per)++cnt;//����������֮ǰ���ǲ�ͬ�����־ͼ���++
        per=a[disc[i].ki];//����ǰ��
        a[disc[i].ki]=cnt;//�ٰ�cnt���ԭ���飬�������ˡ�
    }
    return;
}
int a[MAXN],n;
int main()
{
    return 0;
}
