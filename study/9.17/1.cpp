#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        int cnt = 0;
        if (n == 1 || m == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    printf("%d ", ++cnt);
                }
                printf("\n");
            }
            continue;
        }
        if (n % 2 == 1 && m % 2 == 1)
        {
            printf("-1\n");
            continue;
        }
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    printf("%d ", ++cnt);
                }
                printf("\n");
            }
            continue;
        }
        else
        {
            int cnt1 = 0;
            int cnt2 = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j % 2 == 1)
                    {
                        printf("%d ", cnt1++ * 2 + 1);
                    }
                    else
                    {
                        printf("%d ", ++cnt2 * 2);
                    }
                }
                printf("\n");
            }
        }
        continue;
    }
}
