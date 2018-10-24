#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
void fre()
{
    freopen("c://test//input.in", "r", stdin);
    freopen("c://test//output.out", "w", stdout);
}
#define MS(x, y) memset(x, y, sizeof(x))
#define MC(x, y) memcpy(x, y, sizeof(x))
#define MP(x, y) make_pair(x, y)
#define ls o << 1
#define rs o << 1 | 1typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T>
inline void gmax(T &a, T b)
{
    if (b > a)
        a = b;
}
template <class T>
inline void gmin(T &a, T b)
{
    if (b < a)
        a = b;
}
const int N = 55, M = 0, Z = 1e9 + 7, maxint = 2147483647, ms31 = 522133279, ms63 = 1061109567, ms127 = 2139062143;
const double eps = 1e-8, PI = acos(-1.0); //.0
int casenum, casei;
UI m;
int a[12], c[12], b[12], e[12];
int ans;
void init()
{
    c[1] = 1;
    c[2] = 5;
    c[3] = 10;
    c[4] = 20;
    c[5] = 50;
    c[6] = 100;
    c[7] = 200;
    c[8] = 500;
    c[9] = 1000;
    c[10] = 2000;
}
int cntmin(UI tmp, int p)
{
    int num = 0;
    for (int i = p; i >= 1; i--)
    {
        if (e[i] == -1)
        {
            int g = min((UI)b[i], tmp / c[i]);
            num += g;
            tmp -= g * c[i];
        }
        else
        {
            int g = min((UI)b[i], tmp / c[i]);
            if (g & 1)
                --g;
            num += g;
            tmp -= g * c[i];
        }
    }
    if (tmp == 0)
        return num;
    else
        return -1;
}
void tryit()
{
    if (e[5] > a[5] || e[8] > a[8])
        return;
    MS(b, 0);
    int num = e[5] + e[8];
    UI tmp = e[5] * 50 + e[8] * 500;
    for (int i = 1; i <= 10; i++)
    {
        if (e[i] == -1)
        {
            num += a[i];
            b[i] = a[i];
            tmp += a[i] * c[i];
        }
        else
        {
            b[i] = a[i] - e[i];
            if (b[i] & 1)
                --b[i];
            num += b[i];
            tmp += b[i] * c[i];
        }
        if (tmp >= m)
        {
            int more = tmp - m;
            int over = cntmin(more, i);
            if (~over)
            {
                num -= over;
                gmax(ans, num);
            }
            return;
        }
    }
}
int main()
{
    init();
    scanf("%d", &casenum);
    for (casei = 1; casei <= casenum; casei++)
    {
        scanf("%d", &m);
        for (int i = 1; i <= 10; i++)
            scanf("%d", &a[i]);
        MS(e, -1);
        ans = -1;
        e[5] = 0;
        e[8] = 0;
        tryit();
        e[5] = 0;
        e[8] = 1;
        tryit();
        e[5] = 1;
        e[8] = 0;
        tryit();
        e[5] = 1;
        e[8] = 1;
        tryit();
        printf("%d\n", ans);
    }
    return 0;
}
