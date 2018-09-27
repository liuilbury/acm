#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 5000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
long long f, l;
int main()
{
    int T;
    int n;
    int li, fi;
    ll sum = 0;
    //freopen("6.in", "r", stdin);
    //freopen("6.out", "w", stdout);
    while (scanf("%d", &n) != EOF)
    {
        sum = 0;
        l = 1;
        li = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &f);
            for (int j = 62; j >= 0; j--)
            {
                if (((f >> j) & 1) == 1)
                {
                    fi = j;
                    sum += fi + li + 2;
                    for (int k = fi, p = li; k >= 0 && p >= 0; k--, p--)
                    {
                        if (((f >> k) & 1) == ((l >> p) & 1))
                        {
                            sum -= 2;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    break;
                }
            }
            l = f;
            li = fi;
        }
        printf("%lld\n", sum);
    }
}