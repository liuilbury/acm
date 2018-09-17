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
    freopen("1.txt", "w", stdout);
    printf("1\n");
    //int max1 = random(-10000, 10000);
    //int min1 = random(-10000, 10000);
    printf("1000 5 %d\n", random(-1000, 1000));
    int n = 1000;
    for (int i = 1; i <= n; i++)
    {
        int t = random(-1000, 1000);
        while(!t)
        {
            t = random(-1000, 1000);
        }
        printf("%d ", t);
    }
    printf("\n");
    printf("/*/*/\n");
}