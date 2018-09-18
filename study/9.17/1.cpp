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
int A[1000005], B[1000005];
int main()
{
    int T, a, b, c, d, e;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        for (int i = 0; i <= e; i++)
        {
            A[i] = 0;
            B[i] = 0;
        }
        if (b - a >= e)
        {
            for (int i = 0; i < e; i++)
            {
                A[i] = 1;
            }
        }
        else if (a % e <= b % e)
        {
            for (int i = a % e; i <= b % e; i++)
            {
                A[i] = 1;
            }
        }
        else
        {
            for (int i = 0; i <= b % e; i++)
            {
                A[i] = 1;
            }
            for (int i = a % e; i < e; i++)
            {
                A[i] = 1;
            }
        }
        if (d - c >= e)
        {
            for (int i = 0; i < e; i++)
            {
                B[i] = 1;
            }
        }
        else if (c % e <= d % e)
        {
            for (int i = c % e; i <= d % e; i++)
            {
                B[i] = 1;
            }
        }
        else
        {
            for (int i = 0; i <= d % e; i++)
            {
                B[i] = 1;
            }
            for (int i = c % e; i < e; i++)
            {
                B[i] = 1;
            }
        }
        int flag = 0;
        if (A[0] == 1 && B[0] == 0)
        {
            flag = 1;
        }
        else
        {
            for (int i = 1; i < e; i++)
            {
                if (A[i] == 1 && B[e - i] == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
        {
            printf("WIN\n");
        }
        else
            printf("LOSE\n");
    }
}