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
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d\n", n * m / 2);
    }
}
