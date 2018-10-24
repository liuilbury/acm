#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100005;
int str[maxn];      //原字符串
int tmp[maxn << 1]; //转换后的字符串
int Len[maxn << 1];
//转换原始串
int N;
int INIT(int *st)
{
    int i, len = N;
    tmp[0] = -2; //字符串开头增加一个特殊数字，防止越界
    tmp[1] = -1;
    for (i = 0; i < len; i++)
    {
        tmp[(i + 1) << 1] = st[i];
        tmp[((i + 1) << 1) + 1] = -1;
    }
    tmp[2 * len + 1] = -1;
    tmp[2 * len + 2] = -3; //字符串结尾加一个数字，防止越界
    tmp[2 * len + 3] = 0;
    return 2 * len + 1; //返回转换字符串的长度
}
//Manacher算法计算过程
int MANACHER(int *st, int len)
{
    memset(Len, 0, sizeof Len);
    int ans = 0, pos = 0;
    for (int i = 1; i <= len; i++)
    {
        bool label = true;
        if (Len[pos] + pos > i)
            Len[i] = min(Len[2 * pos - i], Len[pos] + pos - i);
        else
            Len[i] = 1;
        while (st[i - Len[i]] == st[i + Len[i]] && label)
        {
            if (st[i - Len[i]] < 0) //若为插入数字
                Len[i]++;
            else if (st[i - Len[i]] <= st[i + Len[i] - 2])
                Len[i]++;
            else //不满足单调性，则退出while循环
                label = false;
        }
        if (Len[i] + i > pos + Len[pos])
        {
            pos = i;
        }
        ans = max(ans, Len[i]);
    }
    return ans - 1; //返回Len[i]中的最大值-1即为原串的最长回文子串额长度
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &str[i]);
        }
        int tnum = INIT(str);
        printf("%d\n", MANACHER(tmp, tnum));
    }
    return 0;
}
