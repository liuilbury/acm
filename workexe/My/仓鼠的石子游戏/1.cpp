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
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);

        int n;
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            if (a == 1)
                cnt++;
        }
        if (cnt % 2 == 1)
            puts("rabbit");
        else
            puts("hamster");
}
