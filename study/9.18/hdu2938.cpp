#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 1e5 + 5;
int i, i0, n, k, r, mp[100005], tmp,to[100005],cnt[100005],pre[100005],ans[100005],f;
bool vis[100005];
struct node
{
    int rem, div;
};
vector<node> v;
int fin(int x)
{
    tmp = 0;
    int now = x, v1 = 0;
    f = 1;
    while (1)
    {
        pre[now]=v.size();
        if (vis[now])
            return v1;
        tmp++;
        cnt[now]=tmp;
        vis[now] = 1;
        now = mp[now];
        v1 += f;
        if (now == to[x])
            f = 0;
    }
}
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    LL re = exgcd(b, a % b, x, y), tmp = x;
    x = y, y = tmp - (a / b) * y;
    return re;
}
LL m[maxn], a[maxn];
LL work()
{
    LL M = v[0].div, A = v[0].rem, t, d, x, y;
    int i;
    for (i = 1; i < v.size(); i++)
    {
        d = exgcd(M, v[i].div, x, y); //解方程
        if ((v[i].rem - A) % d)
            return -1;                                                  //无解
        x *= (v[i].rem - A) / d, t = v[i].div / d, x = (x % t + t) % t; //求x
        A = M * x + A, M = M / d * v[i].div, A %= M;                    //日常膜一膜（划掉）模一模，防止爆
    }
    A = (A % M + M) % M;
    return A;
}
int main()
{
    while (~scanf("%d", &n) && n)
    {
        v.clear();
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &mp[i]);
        }
        memset(vis, 0, sizeof(vis));
        memset(ans,-1,sizeof(ans));
        bool ff=1;
        for (i = 1; i <= n; i++)
        {
            scanf("%d",&to[i]);
            if(vis[i]==0)
            {
                r = fin(i);
                if(f)ff=0;
                v.push_back({r, tmp});
            }
        }
        for(i=1;i<=n;i++)
        {
            int tmp;
            if(cnt[to[i]]<cnt[i])
            {
                tmp=v[pre[i]].div-cnt[i]+cnt[to[i]];
            }
            else
            {
                tmp=cnt[to[i]]-cnt[i];
            }
            //printf("%d %d %d---\n",i,to[i],tmp);
            if(ans[pre[i]]==-1)ans[pre[i]]=tmp;
            else
            {
                if(ans[pre[i]]!=tmp)ff=0;
            }
        }
        if(ff)printf("%lld\n", work());
        else printf("-1\n");
    }
    return 0;
}
