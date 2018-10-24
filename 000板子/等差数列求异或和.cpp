#include <cstdio>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 5000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
long long Get(long long dis, long long l, long long P, long long number)
{
    long long ret = 0;
    ret += (l / P) * number;
    l %= P;
    ret += (dis / P) * number * (number - 1) / 2;
    dis %= P;
    if (dis * number + l < P)
        return ret;
    else
        return ret + Get(P, (dis * number + l) % P, dis, (dis * number + l) / P);
}
long long Get_Xor(long long l, long long r, long long dis)
{
    if ((r - l) % dis != 0)
    {
        r = (r - l) / dis * dis + l;
    }
    long long number = (r - l) / dis + 1, ans = 0, Sum, P = 1;
    for (long long i = 1; i <= 32; i++)
    {
        Sum = Get(dis, l, P, number);
        if (Sum & 1)
            ans += P;
        P <<= 1;
    }
    return ans;
}
long long a[20008], b[20008], c[20008];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {

            scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
            b[i] = (b[i] - a[i]) / c[i] * c[i] + a[i];
            //printf("%d\n", b[i]);
            ans ^= Get_Xor(a[i], b[i], c[i]);
        }
        if (ans == 0)
            puts("DC Qiang is unhappy.");
        else
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if((ans-a[i])%c[i]==0&&ans<=b[i]&&ans>=a[i])
                {
                    cnt++;
                }
            }
            printf("%lld %d\n", ans, cnt);
        }
    }
}