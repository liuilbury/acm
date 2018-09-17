#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
const int MAXN=20010;//点数的最大值
const int MAXM=880010;//边数的最大值
const int INF=0x3f3f3f3f;
struct Node
{
    int from,to,next;
    ll cap;
}edge[MAXM];
int tol;
int head[MAXN];
int dep[MAXN];
int gap[MAXN];//gap[x]=y :说明残留网络中dep[i]==x的个数为y

int n;//n是总的点的个数，包括源点和汇点

void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v,ll w)
{
    edge[tol].from=u;
    edge[tol].to=v;
    edge[tol].cap=w;
    edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].from=v;
    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].next=head[v];
    head[v]=tol++;
}
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int que[MAXN];
    int front,rear;
    front=rear=0;
    dep[end]=0;
    que[rear++]=end;
    while(front!=rear)
    {
        int u=que[front++];
        if(front==MAXN)front=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=-1)continue;
            que[rear++]=v;
            if(rear==MAXN)rear=0;
            dep[v]=dep[u]+1;
            ++gap[dep[v]];
        }
    }
}
ll SAP(int start,int end)
{
    ll res=0;
    BFS(start,end);
    int cur[MAXN];
    int S[MAXN];
    int top=0;
    memcpy(cur,head,sizeof(head));
    int u=start;
    int i;
    while(dep[start]<n)
    {
        if(u==end)
        {
            ll temp=INF;
            int inser;
            for(i=0;i<top;i++)
               if(temp>edge[S[i]].cap)
               {
                   temp=edge[S[i]].cap;
                   inser=i;
               }
            for(i=0;i<top;i++)
            {
                edge[S[i]].cap-=temp;
                edge[S[i]^1].cap+=temp;
            }
            res+=temp;
            top=inser;
            u=edge[S[top]].from;
        }
        if(u!=end&&gap[dep[u]-1]==0)//出现断层，无增广路
          break;
        for(i=cur[u];i!=-1;i=edge[i].next)
           if(edge[i].cap!=0&&dep[u]==dep[edge[i].to]+1)
             break;
        if(i!=-1)
        {
            cur[u]=i;
            S[top++]=i;
            u=edge[i].to;
        }
        else
        {
            int min=n;
            for(i=head[u];i!=-1;i=edge[i].next)
            {
                if(edge[i].cap==0)continue;
                if(min>dep[edge[i].to])
                {
                    min=dep[edge[i].to];
                    cur[u]=i;
                }
            }
            --gap[dep[u]];
            dep[u]=min+1;
            ++gap[dep[u]];
            if(u!=start)u=edge[S[--top]].from;
        }
    }
    return res;
}
ll a[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        ll sum = 0;
        scanf("%d",&n);
        for (int i = 1; i <= n;i++)
        {
            scanf("%lld", &a[i]);
        }
        for (int i = 1; i <= n;i++)
        {
            for (int j = i + i; j <= n;j+=i)
            {
                addedge(i, j, (ll)1e18);
            }
            if(a[i]>0)
            {
                addedge(i, n + 1, a[i]);
                sum += a[i];
            }
            else
            {
                addedge(n + 2, i, -a[i]);
            }
        }
        int s = n + 2, t = n + 1;
        n += 2;
        printf("%lld\n", sum - SAP(s,t));
    }
}