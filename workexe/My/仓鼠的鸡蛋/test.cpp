#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 2e5 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
int a[MAXN];
int n, m, k;
int mp[MAXN];
bool check(int x)
{
    for (int i = 1; i <= m; i++)
    {
        mp[i] = k;
    }
    int cnt = 1;
    for (int i = x; i <= n; i++)
    {
        if(mp[cnt]>=a[i])
        {
            mp[cnt] -= a[i];
        }
        else
        {
            cnt++;
            if(cnt>m)
            {
                return false;
            }
            else
            {
                mp[cnt] -= a[i];
            }
        }
    }
    return true;
}
int main()
{

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int l = 1;
    int r = n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", n-l+1);
}
