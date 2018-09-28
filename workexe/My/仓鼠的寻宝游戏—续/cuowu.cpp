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
set<int> s;
int cnt = 0;
void go(int x)
{
    if (s.count(x) || x == 1)
        return;
    s.insert(x);
    cnt++;
    x /= 2;
    go(x);
}
int main()
{
    int n;
    //freopen("test/6.in", "r", stdin);
    //freopen("test/6.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        go(a);
    }
    printf("%d\n", cnt);
}
