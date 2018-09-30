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
struct pop
{
    char word[32];
    int l;
    int t;
} s[1000005];
int cmp1(pop a, pop b)
{
    return strcmp(a.word, b.word) < 0;
}
int main()
{
    int T;
    int n;
    //freopen("test/6.in", "r", stdin);
    //freopen("test/6.out", "w", stdout);
    scanf("%d", &T);
    int max1 = 0;
    for (int i0 = 1; i0 <= T; i0++)
    {
        scanf("%d", &n);
        int cnt1 = 0;
        for (int i = 30; i >= 0; i--)
        {
            int id = (n >> i) & 1;
            if (id == 1)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    id = (n >> j) & 1;
                    s[i0].word[cnt1] = id + '0';
                    //printf("%d", id);
                    cnt1++;
                }
                break;
            }
        }
        s[i0].l = cnt1;
        max1 = max(s[i0].l, max1);
    }
    int cnt = 0;
    sort(s + 1, s + 1 + T, cmp1);
    for (int i = 1; i <= T; i++)
    {
        if (s[i].l == s[i - 1].l)
        {
            if (strcmp(s[i].word, s[i - 1].word) == 0)
            {
                s[i].t = 0;
                continue;
            }
        }
        int flag = 0;
        int cc = 0;
        int l = min(s[i].l, s[i - 1].l);
        for (int j = 0; j < l; j++)
        {
            if (s[i].word[j] == s[i - 1].word[j])
            {
                s[i].t = 0;
                continue;
            }
            else
            {
                flag = 1;
                cc = j;
                break;
            }
        }
        if (flag == 0)
        {
            cnt += s[i].l - s[i - 1].l;
            s[i].t = s[i].l - s[i - 1].l;
        }
        else
        {
            cnt += s[i].l - cc;
            s[i].t = s[i].l - cc;
        }
    }
    printf("%d\n", 2 * cnt - max1);
    /* int m;
    scanf("%d", &m);
    for (int i = 1; i <= m;i++)
    {
        int f, t;
        scanf("%d %d", &f, &t);
        for (int j = 1; j <= t;j++)
        {

        }
    } */
}
