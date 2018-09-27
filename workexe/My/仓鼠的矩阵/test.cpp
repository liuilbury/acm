#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 5000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
int a[10005];
int b[10005];
int c[10005];
int dx[4] = {-1, 1, 1, -1};
int dy[4] = {1, 1, -1, -1};
bool vis[105][105];
int map1[105][105];
int n, m;
int mp[4];
bool check(int y, int x)
{
    if (y >= 1 && y <= n && x <= m && x >= 1)
    {
        return true;
    }
    return false;
}
void dfs(int y, int x, int deep)
{
    vis[y][x] = 1;
    map1[y][x] = deep % 2;
    mp[deep % 2]++;
    for (int i = 0; i < 4; i++)
    {
        if (check(y + dy[i], x + dx[i]) && vis[y + dy[i]][x + dx[i]] == 0)
        {
            dfs(y + dy[i], x + dx[i], deep + 1);
        }
    }
}
void dfs1(int y, int x, int deep)
{
    vis[y][x] = 1;
    if (deep % 2 == 1)
    {
        map1[y][x] = 2;
        mp[2]++;
    }
    else
    {
        map1[y][x] = 3;
        mp[3]++;
    }
    for (int i = 0; i < 4; i++)
    {
        if (check(y + dy[i], x + dx[i]) && vis[y + dy[i]][x + dx[i]] == 0)
        {
            dfs1(y + dy[i], x + dx[i], deep + 1);
        }
    }
}
int main()
{
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        mem(mp, 0);
        int cnt = 0;
        int cnt1 = 0;
        for (int i = 1; i <= n * m; i++)
        {
            scanf("%d", &c[i]);
            if (c[i] % 2 == 0)
            {
                a[++cnt] = c[i];
            }
            if (c[i] % 2 == 1)
            {
                b[++cnt1] = c[i];
            }
        }
        if (n == 1 || m == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    printf("%d ", c[i * m + j - m]);
                }
                printf("\n");
            }
            continue;
        }
        dfs(1, 1, 1);
        mem(vis, 0);
        dfs1(1, 2, 1);
        if (mp[0] + mp[2] == cnt)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (map1[i][j] == 0 || map1[i][j] == 2)
                    {
                        printf("%d ", a[cnt--]);
                    }
                    else
                        printf("%d ", b[cnt1--]);
                }
                printf("\n");
            }
        }
        else if (mp[0] + mp[2] == cnt1)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (map1[i][j] == 0 || map1[i][j] == 2)
                    {
                        printf("%d ", b[cnt1--]);
                    }
                    else
                        printf("%d ", a[cnt--]);
                }
                printf("\n");
            }
        }
        else if (mp[0] + mp[3] == cnt)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (map1[i][j] == 0 || map1[i][j] == 3)
                    {
                        printf("%d ", a[cnt--]);
                    }
                    else
                        printf("%d ", b[cnt1--]);
                }
                printf("\n");
            }
        }
        else if (mp[0] + mp[3] == cnt1)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (map1[i][j] == 0 || map1[i][j] == 3)
                    {
                        printf("%d ", b[cnt1--]);
                    }
                    else
                        printf("%d ", a[cnt--]);
                }
                printf("\n");
            }
        }
        else
            printf("-1\n");
    }
}