#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a, 0, sizeof(a));
#define max(x, y) (x) > (y) ? (x) : (y)
#define min(x, y) (x) < (y) ? (x) : (y)
#define Fopen                      \
    freopen("in.txt", "r", stdin); \
    freopen("out.txt", "w", stdout);
#define rep(i, n) for (int i = 1; i <= (n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;

char s[20][20];
int cal(char ch)
{
    return ch - '0';
}
bool dp[82][10];
int w[10];
void max1(char a1, char a2, char a3)
{
    w[1] = cal(a1);
    w[2] = cal(a2);
    w[3] = cal(a3);
}
void max2(char a1, char a2)
{
    w[1] = cal(a1);
    w[2] = cal(a2);
}
int zhongxin[10];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        mm(dp);
        dp[0][0] = 1;
        for (int i = 1; i <= 9; i++)
            scanf("%s", s[i] + 1);

        max1(s[1][4], s[4][1], s[4][12]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max1(s[1][6], s[4][9], s[4][10]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max1(s[3][4], s[4][3], s[4][4]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max1(s[3][6], s[4][6], s[4][7]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max1(s[6][1], s[6][12], s[9][4]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max1(s[6][3], s[6][4], s[7][4]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max1(s[6][6], s[6][7], s[7][6]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max1(s[9][6], s[6][9], s[6][10]);
        for (int i = 4; i >= 1; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 3; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);

        max2(s[6][11], s[9][5]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[3][5], s[4][5]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[2][4], s[4][2]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[2][6], s[4][8]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[5][1], s[5][12]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[6][2], s[8][4]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[8][6], s[6][8]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[5][3], s[5][4]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[5][6], s[5][7]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[5][9], s[5][10]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[4][11], s[1][5]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);
        max2(s[6][5], s[7][5]);
        for (int i = 8; i >= 5; i--)
            for (int j = 81; j >= 0; j--)
                for (int k = 1; k <= 2; k++)
                    if (j >= w[k])
                        dp[j][i] = max(dp[j - w[k]][i - 1], dp[j][i]);

        zhongxin[1] = cal(s[2][5]);
        zhongxin[2] = cal(s[5][5]);
        zhongxin[3] = cal(s[8][5]);
        zhongxin[4] = cal(s[5][2]);
        zhongxin[5] = cal(s[5][8]);
        zhongxin[6] = cal(s[5][11]);
        for (int j = 81; j >= 0; j--)
            for (int k = 1; k <= 6; k++)
                if (j >= zhongxin[k])
                    dp[j][9] = max(dp[j - w[k]][8], dp[j][9]);
        int cas;
        scanf("%d", &cas);
        while (cas--)
        {
            int x;
            scanf("%d", &x);
            if (dp[x][9])
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
