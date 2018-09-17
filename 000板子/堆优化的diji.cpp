/*
使用优先队列Dijkstra算法
复杂度O(ElogE)
注意对vector<Edge> E[MAXN]进行初始化后加边
*/
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
const int MAXN = 300000;
struct qnode
{
    long long v;
    long long c;
    qnode(long long _v = 0, long long _c = 0) : v(_v), c(_c) {}
    bool operator<(const qnode &r) const
    {
        return c > r.c;
    }
};
struct Edge
{
    long long v, cost, cost2;
    Edge(long long _v = 0, long long _cost = 0, long long _cost2 = 0) : v(_v), cost(_cost), cost2(_cost2) {}
};
vector<Edge> E[MAXN];
bool vis[MAXN];
long long dist[MAXN];
void Dijkstra(int n, int start) //点的编号从1开始
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    priority_queue<qnode> que;
    while (!que.empty())
        que.pop();
    dist[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while (!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++)
        {
            long long v = E[tmp.v][i].v;
            long long cost = E[u][i].cost;
            if (!vis[v] && dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                que.push(qnode(v, dist[v]));
            }
        }
    }
}
void addedge(long long u, long long v, long long a, long long b)
{
    E[u].push_back(Edge(v, a, b));
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i <= MAXN; i++)
            if (!E[i].empty())
                E[i].clear();
        //freopen("in.txt", "r", stdin);
        int n;
        scanf("%d", &n);
        int m;
        scanf("%d", &m);
        long long u, v, w, a, b;
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld %lld %lld %lld", &u, &v, &a, &b);
            addedge(u, v, a, b);
        }
        Dijkstra(n, 1);
        /* for (int i = 1; i <= n;i++)
        {
            cout << dist[i] << endl;
        } */
        if (dist[n] == 1e17)
            printf("-1\n");
        else
            printf("%lld\n", (long long)log2(dist[n]));
    }
    return 0;
}
