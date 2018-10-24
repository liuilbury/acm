#include<bits/stdc++.h>
int i, n, j, A;
template <class T>
void ss(T &ret)
{
    char c;
    int sgn;
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
    ret *= sgn;
}
void pp(int a)
{
    if (a > 9)
        pp(a / 10);
    putchar(a % 10 + '0');
}int rank[100];
main()
{
    ss(n);
    A = 0;
    for (i = 1; i < n; i++)
    {
        ss(j);
        A += j;
        if (A >= 0)
            pp(A);
        else
            putchar('-'), pp(-A);
        putchar(' ');
    }
    ss(j);
    A += j;
    if (A >= 0)
        pp(A);
    else
        putchar('-'), pp(-A);
    putchar('\n');
}