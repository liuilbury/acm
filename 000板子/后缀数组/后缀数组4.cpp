#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int MAXN = 51000;
//以下为倍增算法求后缀数组
int wa[MAXN], wb[MAXN], wv[MAXN], Ws[MAXN];
int w[MAXN];
int lolo[MAXN];
int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
/**< 传入参数：str,sa,len+1,ASCII_MAX+1 */
void da(int sa[], int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++)
        Ws[i] = 0;
    for (i = 0; i < n; i++)
        Ws[x[i] = w[i]]++; //以字符的ascii码为下标
    for (i = 1; i < m; i++)
        Ws[i] += Ws[i - 1];
    for (i = n - 1; i >= 0; i--)
        sa[--Ws[x[i]]] = i;
    /*cout<<"SA"<<endl;;
      for(int i=0;i<n+1;i++)cout<<sa[i]<<' ';*/
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++)
            y[p++] = i;
        for (i = 0; i < n; i++)
            if (sa[i] >= j)
                y[p++] = sa[i] - j;
        for (i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for (i = 0; i < m; i++)
            Ws[i] = 0;
        for (i = 0; i < n; i++)
            Ws[wv[i]]++;
        for (i = 1; i < m; i++)
            Ws[i] += Ws[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--Ws[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}
int sa[MAXN], Rank[MAXN], height[MAXN];
//求height数组
/**< str,sa,len */
void calheight(int *sa, int n)
{
    int i, j, k = 0;
    for (i = 1; i <= n; i++)
        Rank[sa[i]] = i;
    for (i = 0; i < n; height[Rank[i++]] = k)
        for (k ? k-- : 0, j = sa[Rank[i] - 1]; w[i + k] == w[j + k]; k++)
            ;
    // Unified
    for (int i = n; i >= 1; --i)
        ++sa[i], Rank[i] = Rank[i - 1];
}
string str;
string str1;
string s[105];
void debug(int len)
{
    puts("--------------All Suffix--------------");
    for (int i = 1; i <= len; ++i)
    {
        printf("%d:\t", i);
        for (int j = i - 1; j < len; ++j)
            printf("%c", str[j]);
        puts("");
    }
    puts("");
    puts("-------------After sort---------------");
    for (int i = 1; i <= len; ++i)
    {
        printf("sa[%2d ] = %2d\t", i, sa[i]);
        for (int j = sa[i] - 1; j < len; ++j)
            printf("%d ", w[j]);
        puts("");
    }
    puts("");
    puts("---------------Height-----------------");
    for (int i = 1; i <= len; ++i)
        printf("height[%2d ]=%2d \n", i, height[i]);
    puts("");
    puts("----------------Rank------------------");
    for (int i = 1; i <= len; ++i)
        printf("Rank[%2d ] = %2d\n", i, Rank[i]);
    puts("------------------END-----------------");
}
int n;
int cnt;
int l[210];
bool vis[110];
bool check(int x)
{
    for (int i = 1; i <= cnt; i++)
    {
        if (height[i] >= x)
        {
            for (int j = i + 1; j <= cnt; j++)
            {
                if (height[j] >= x)
                    continue;
                else
                {
                    if (j - i < n - 1)
                    {
                        i = j;
                        break;
                    }
                    memset(vis, false, sizeof(vis));
                    int sum = 0;
                    for (int k = i - 1; k < j; k++)
                    {
                        if (lolo[sa[k]] != -1)
                        {
                            if (vis[lolo[sa[k]]] == 0)
                            {
                                vis[lolo[sa[k]]] = 1;
                                sum++;
                            }
                        }
                    }
                    if (sum == n)
                        return true;
                    i = j;
                    break;
                }
            }
        }
    }
    return false;
}
int main()
{
    int T;
    cin >> n;
    while (T--)
    {
        
    }
    return 0;
}