#include <bits/stdc++.h>
using namespace std;
char s1[2000];
int lps1(char *str, int n)
{
    int dp[10][10], tmp;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;

    for (int i = 1; i < n; ++i)
    {
        tmp = 0;
        //考虑所有连续的长度为i+1的子串，str[j....j+i]
        for (int j = 0; j + i < n; j++)
        {
            //如果首尾相同
            if (str[j] == str[j + i])
                tmp = dp[j + 1][j + i - 1] + 2;
            //如果首尾不同
            else
                tmp = max(dp[j + 1][j + i], dp[j][j + i - 1]);
            dp[j][j + i] = tmp;
        }
    }
    return dp[0][n - 1]; //返回字符串str[0...n-1]的最长回文子序列长度
}
int main()
{
    scanf("%s", s1);
    int n = strlen(s1);
    for (int i = 0; i < n; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] = s1[i] - 'A' + 'a';
        }
    }
    int res = lps1(0, n - 1);
    cout << n - res << endl;
    return 0;
}