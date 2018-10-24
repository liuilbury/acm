#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-10
#define PI acos(-1.0)
#define ll long long
int const maxn = 1e5+7;
const int mod = 1e9 + 7;
int gcd(int a, int b) {
    if (b == 0) return a;  return gcd(b, a % b);
}

int p,ans,c[11];
int val[11]={0,1,5,10,20,50,100,200,500,1000,2000};
ll sum[11];

void dfs(int rest,int idx,int cnt)
{
    if(rest<0)
        return;
    if(idx==0)
    {
        if(rest==0)
            ans=max(ans,cnt);
        return;
    }
    ll cur = max(rest-sum[idx-1],(ll)0);
    int curnum=cur/val[idx];
    if(cur % val[idx])
        curnum++;
    if(curnum<=c[idx])
        dfs(rest-curnum*val[idx],idx-1,cnt+curnum);
    curnum++;
    if(curnum<=c[idx])
        dfs(rest-curnum*val[idx],idx-1,cnt+curnum);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(sum,0,sizeof(sum));
        ans=-1;
        scanf("%d",&p);
        for(int i=1;i<=10;i++)
            scanf("%d",&c[i]);
        for(int i=1;i<=10;i++)
            sum[i]=sum[i-1]+(ll)(val[i]*c[i]);
        dfs(p,10,0);
        printf("%d\n",ans);
    }
    return 0;
}