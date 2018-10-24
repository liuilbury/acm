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
int rand10()
{
    return rand() * 10;
}
int main()
{
    int seed = time(NULL);
    srand(seed);
    printf("%d %d\n", rand10(), rand10());
}
