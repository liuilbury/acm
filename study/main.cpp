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
    int word[3204];
    int l;
    int t;
    int v;
} s[3005],ss[3005];
int cmp1(pop a, pop b)
{
    int lw = min(a.l, b.l);
    for (int i = 0; i < lw;i++)
    {
        if(a.word[i]==b.word[i])
        {
            continue;
        }
        else if(a.word[i]>b.word[i])
        {
            return 0;
        }
        else
            return 1;
    }
    return a.l < b.l;
}
int main()
{
    int T, n;
    //freopen("test/6.in", "r", stdin);
    //freopen("test/6.out", "w", stdout);
    scanf("%d", &T);
    int max1 = 0;
    for (int i0 = 1; i0 <= T; i0++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &s[i0].word[i]);
        }
        s[i0].l = n;
        s[i0].t = i0;
    }
    int cnt = 0;
    sort(s + 1, s + 1 + T, cmp1);
    int cnt1 = 0;
    for (int i = 1; i <= T; i++)
    {
        ss[s[i].t].t = i;
        int flag = 0;
        if (s[i].l == s[i - 1].l)
        {
            for (int j = 0; j < s[i].l;j++)
            {
                if(s[i].word[j]==s[i-1].word[j])
                {
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
                continue;
        }
        flag = 0;
        int cc = 0;
        int l = min(s[i].l, s[i - 1].l);
        for (int j = 0; j < l; j++)
        {
            if (s[i].word[j] == s[i - 1].word[j])
            {
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
        }
        else
        {
            cnt += s[i].l - cc;
        }
        ss[s[i].t].v = cnt - cnt1;
        cnt1=cnt;
    }
    printf("%d\n", cnt);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int f, t;
        scanf("%d %d", &f, &t);
        for (int j = 1; j <= n; j++)
        {
            if (s[j].t == f)
            {
                for (int k = 0; k < t; k++)
                {
                    scanf("%d", &s[j].word[k]);
                }
                s[j].word[t] = '\0';
                s[j].l = t;
                break;
            }
        }
        int cnt = 0;
        sort(s + 1, s + 1 + T, cmp1);
        for (int i = 1; i <= T; i++)
        {
            int flag = 0;
            if (s[i].l == s[i - 1].l)
            {
                for (int j = 0; j < s[i].l; j++)
                {
                    if (s[i].word[j] == s[i - 1].word[j])
                    {
                        continue;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    continue;
            }
            flag = 0;
            int cc = 0;
            int l = min(s[i].l, s[i - 1].l);
            for (int j = 0; j < l; j++)
            {
                if (s[i].word[j] == s[i - 1].word[j])
                {
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
            }
            else
            {
                cnt += s[i].l - cc;
            }
        }
        printf("%d\n", cnt);
    }
}