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
int map1[105][105];
int main()
{
    int n, m, k;
    //freopen("test/1.in", "r", stdin);
    //freopen("test/1.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    mem(map1, 0);
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        map1[x][y] += i;
        map1[x - 1][y] += i;
        map1[x][y - 1] += i;
        map1[x + 1][y] += i;
        map1[x][y + 1] += i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j == 1)
            {
                if (map1[i][j] == 0)
                    printf("*");
                else
                    printf("%d", map1[i][j]);
            }
            else
            {
                if (map1[i][j] == 0)
                    printf(" *");
                else
                    printf(" %d", map1[i][j]);
            }
        }
        printf("\n");
    }
}