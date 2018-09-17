#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
int pre[MAXN];
int find(int x)
{
    if(pre[x]!=x)
        return  pre[x]=find(pre[x]);
    else
        return x;
}
void join(int x,int y)
{
    int fx = find(x), fy = find(y);
    if(fx!=fy)
    {
        pre[fx] = fy;
    }
}
int main()
{
    int n, m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for (int i = 1; i <= m;i++)
        {
            int w,e;
            scanf("%d %d", &w,&e);
            pre[w] = e;
        }
        int cnt = 0;
        for (int i = 1; i <= n;i++)
        {
            if(find(i)=pre[i])
                cnt++;
        }
        printf("%d\n", cnt);
    }
}