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
int checkk[11] = {0, 1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
int liu[11];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int p;
        scanf("%d", &p);
        int c[11];
        mem(liu, 0);
        int cnt = 0, sum = 0;
        for (int i = 1; i <= 10; i++)
        {
            scanf("%d", &c[i]);
            sum += c[i] * checkk[i];
        }
        int ans = 0;
        int flag = 0;
        int k = c[8];
        int maxx = -1;
        p = sum - p;
        if (p < 0)
            printf("-1\n");
        else
        {
            cnt = 0;
            ans = 0;
            for (int i = 10; i >= 1; i--)
            {
                if ((p - ans) / checkk[i] <= c[i])
                {
                    liu[i] = c[i] - (p - ans) / checkk[i];
                    ans += (p - ans) / checkk[i] * checkk[i];
                }
                else
                {
                    ans += checkk[i] * c[i];
                    liu[i] = 0;
                }
            }
            for (int i = 1; i <= 10; i++)
            {
                cnt += liu[i];
            }
            if (ans == p)
                maxx = max(cnt, maxx);
            cnt = 0;
            ans = 0;
            mem(liu, 0);
            int t = p;
            for (int i = 10; i >= 1; i--)
            {
                if (i == 8)
                {
                    t -= 500;
                }
                if (i == 7)
                {
                    t += 500;
                }
                if (t <= ans)
                    break;
                if ((t - ans) / checkk[i] <= c[i])
                {
                    liu[i] = c[i] - (t - ans) / checkk[i];
                    ans += (t - ans) / checkk[i] * checkk[i];
                }
                else
                {
                    ans += checkk[i] * c[i];
                    liu[i] = 0;
                }
            }
            for (int i = 1; i <= 10; i++)
            {
                cnt += liu[i];
            }
            if (ans == p)
                maxx = max(cnt, maxx);
            cnt = 0;
            ans = 0;
            mem(liu, 0);
            t = p;
            for (int i = 10; i >= 1; i--)
            {
                if (i == 8)
                {
                    t -= 500;
                }
                if (i == 7)
                {
                    t += 500;
                }
                if (i == 5)
                    t -= 50;
                if (i == 4)
                    t += 50;
                if (t <= ans)
                    break;
                if ((t - ans) / checkk[i] <= c[i])
                {
                    liu[i] = c[i] - (t - ans) / checkk[i];
                    ans += (t - ans) / checkk[i] * checkk[i];
                }
                else
                {
                    ans += checkk[i] * c[i];
                    liu[i] = 0;
                }
            }
            for (int i = 1; i <= 10; i++)
            {
                cnt += liu[i];
            }
            if (ans == p)
                maxx = max(cnt, maxx);
            cnt = 0;
            ans = 0;
            mem(liu, 0);
            t = p;
            for (int i = 10; i >= 1; i--)
            {
                if (i == 5)
                    t -= 50;
                if (i == 4)
                    t += 50;
                if (t <= ans)
                    break;
                if ((t - ans) / checkk[i] <= c[i])
                {
                    liu[i] = c[i] - (t - ans) / checkk[i];
                    ans += (t - ans) / checkk[i] * checkk[i];
                }
                else
                {
                    ans += checkk[i] * c[i];
                    liu[i] = 0;
                }
            }
            for (int i = 1; i <= 10; i++)
            {
                cnt += liu[i];
            }
            if (ans == p)
                maxx = max(cnt, maxx);
            cnt = 0;
            if (maxx == -1)
                printf("-1\n");
            else
                printf("%d\n", maxx);
        }
    }
}