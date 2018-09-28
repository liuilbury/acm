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
const ll MAXN = 1000000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
ll trie[32 * MAXN][2];
ll a[MAXN];
ll max1 = 0;
ll tot;
int f;
void insert(ll d)
{
    int root = 0;
    ll cnt = 0;
    for (int i = 32; i >= 0; i--)
    {
        int id = (d >> i) & 1;
        if (id == 1)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                id = (d >> j) & 1;
                //printf("%d", id);
                cnt++;
                if (!trie[root][id])
                    trie[root][id] = ++tot;
                root = trie[root][id];
            }
            break;
        }
    }
    max1 = max(cnt, max1);
}
int main()
{
    int n;
    freopen("test/6.in", "r", stdin);
    freopen("test/6.out", "w", stdout);
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        insert(a[i]);
    }
    ll min1 = 2 * tot;
    printf("%lld\n", min1 - max1);
    return 0;
}
