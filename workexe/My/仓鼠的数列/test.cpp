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
int main()
{
    int n;
    /* freopen("7.in", "r", stdin);
    freopen("7.out", "w", stdout); */
    int a[10000], b[10000];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a + 1, a + 1 + n);
    int l=0, r=0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
            continue;
        else
        {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == b[i])
            continue;
        else
        {
            r = i;
            break;
        }
    }
    if(l==0&&r==0)
        puts("-1");
    else
    {
        printf("%d %d\n", l, r);
    }
}
