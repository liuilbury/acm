#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 45000 + 7;
const ll MOD = 1e9 + 7;
int myrand(int mod) { return ((ll)rand() << 32 ^ (ll)rand() << 16 ^ rand()) % mod; }
#define random(a, b) ((a) + myrand((b) - (a) + 1)) //Integer[a,b]
//-------------------------------------------//
int main(int argc, char *argv[])
{
    stringstream ss;
    int seed = time(NULL);
    if (argc)
    {
        ss << argv[1];
        ss >> seed;
    }
    srand(seed);
    freopen("3.in", "w", stdout);
    int n = 10;
    int m = 10;
    for (int i = 1; i <= n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d %d\n",i,j);
        }
    }
    for (int i = 1; i <= 10;i++)
    {
        printf("%d %d\n", random(1, 100), random(1, 100));
    }
}