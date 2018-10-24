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
char map1[110][110];
char a[11000];
bool vis[110][110];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", map1[i] + 1);
    }
    int x = 1;
    int y = 1;
    int flag = 0;
    int cnt = 0;
    while (1)
    {
        x += dx[flag];
        y += dy[flag];
        if (map1[y][x] == '.')
        {
            continue;
        }
        else if (map1[y][x] == 'W' && vis[y][x] == 0)
        {
            vis[y][x] = 1;
            if (x - 1 != 0)
            {
                flag = 1;
                a[++cnt] = 'W';
            }
        }
        else if (map1[y][x] == 'E' && vis[y][x] == 0)
        {
            vis[y][x] = 1;
            if (x + 1 != m + 1)
            {
                flag = 0;
                a[++cnt] = 'E';
            }
        }
        else if (map1[y][x] == 'N' && vis[y][x] == 0)
        {
            vis[y][x] = 1;
            if (y - 1 != 0)
            {
                flag = 3;
                a[++cnt] = 'N';
            }
        }
        else if (map1[y][x] == 'S' && vis[y][x] == 0)
        {
            vis[y][x] = 1;
            if (y + 1 != n + 1)
            {
                flag = 2;
                a[++cnt] = 'S';
            }
        }
        else if (map1[y][x] == '#')
        {
            printf("%d %d\n", y, x);
            for (int i = 1; i <= cnt; i++)
            {
                printf("%c", a[i]);
            }
            break;
        }
    }
}
