#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], x[500005], y[500005];
string b[500005];
int main()
{
    int t, n, m, k, g;
    long long h;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                scanf("%d", &a[j][i]);
            }
        }
        h = n * m;
        for (int i = 1; i <= k; i++)
        {
            cin >> b[i];
            scanf("%d%d", &x[i], &y[i]);
            if (b[i] == "slammin")
            {
                int q = y[i];
                int w = x[i];
                printf("%d\n", a[w][q]);
                if (a[w][q] == 0)
                    h--;
                if (h == 0)
                    break;
                a[w][q] = 0;
            }
            if (b[i] == "row")
            {
                int q = y[i];
                int w = x[i];
                for (int i = 1; i <= m; i++)
                {
                    g = a[q][i];
                    a[q][i] = a[w][i];
                    a[w][i] = g;
                }
            }
            if (b[i] == "column")
            {
                int q = y[i];
                int w = x[i];
                for (int i = 1; i <= n; i++)
                {
                    g = a[i][q];
                    a[i][q] = a[i][w];
                    a[i][w] = g;
                }
            }
        }
    }
    return 0;
}