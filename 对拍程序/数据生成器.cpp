#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int myrand(int mod) { return ((ll)rand() << 32 ^ (ll)rand() << 16 ^ rand()) % mod; }
#define random(a, b) ((a) + myrand((b) - (a) + 1)) //Integer[a,b]
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
    int n = random(1, 10000);
    printf("%d\n", n);
    // int k = random(1, 1000);
    //assert(1 <= n && n <= 1000);
    // assert(1 <= n && k <= 1000);
    // printf("%d %d\n", n, k);
    for (int j = 1; j <= n;j++)
    {
        int key = random(0, 10000000);
        printf("%d ", key);
        for (int i = 0; i < 10; i++)
        {
            int tmp = random(0, 100000);
            printf("%d%c", tmp, " \n"[i == n - 1]);
        }
    }
    return 0;
}