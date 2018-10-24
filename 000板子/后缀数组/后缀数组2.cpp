#include <cstdio>
#include <cstring>
#include <iostream>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int MAXN = 1000010;
//以下为倍增算法求后缀数组
int wa[MAXN], wb[MAXN], wv[MAXN], Ws[MAXN];
int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void debug(int len)
{
}
/**< 传入参数：str,sa,len+1,ASCII_MAX+1 */
void da(string &r, int sa[], int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++)
        Ws[i] = 0;
    for (i = 0; i < n; i++)
        Ws[x[i] = r[i]]++; //以字符的ascii码为下标
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
int sa[MAXN], rank[MAXN], height[MAXN];
//求height数组
/**< str,sa,len */
void calheight(string &r, int *sa, int n)
{
    int i, j, k = 0;
    for (i = 1; i <= n; i++)
        rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++)
            ;
    // Unified
    for (int i = n; i >= 1; --i)
        ++sa[i], rank[i] = rank[i - 1];
}
string str;
string str1;
map<string, int> mp;
int main()
{
    while (cin >> str)
    {
        int l = str.size();
        int len = l;
        da(str, sa, len + 1, 300);
        calheight(str, sa, len);
        mp.clear();
        //debug(l);
        int cnt = 0;
        for (int i = 1; i <= l; i++)
        {
            if (height[i] > 0 && height[i] <= l / 2)
            {
                string x;
                for (int j = 0; j < height[i]; j++)
                {
                    x += str[sa[i] + j];
                    if (mp[x] == 0)
                    {
                        mp[x] = 1;
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n", cnt);
        /* puts("--------------All Suffix--------------");
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
                printf("%c", str[j]);
            puts("");
        }
        puts("");
        puts("---------------Height-----------------");
        for (int i = 1; i <= len; ++i)
            printf("height[%2d ]=%2d \n", i, height[i]);
        puts("");
        puts("----------------rank------------------");
        for (int i = 1; i <= len; ++i)
            printf("rank[%2d ] = %2d\n", i, rank[i]);
        puts("------------------END-----------------");
        int max1 = 0;
        for (int i = 1; i <= len; ++i)
        {
            if ((sa[i] < l) != (sa[i - 1] < l))
                max1 = max(height[i], max1);
        }
        printf("%d\n", max1);
        for (int i = 1; i <= len; i++)
        {
            printf("%d ", sa[i]);
        } */
    }
    return 0;
}