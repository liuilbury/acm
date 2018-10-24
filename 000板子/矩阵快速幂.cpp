/*
矩阵快速幂模板
by chsobin
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 4;
const int mod = 1000000009;
//矩阵结构体
struct Matrix
{
    int a[maxn][maxn];
    void init()
    { //初始化为单位矩阵
        memset(a, 0, sizeof(a));
        for (int i = 0; i < maxn; ++i)
        {
            a[i][i] = 1;
        }
    }
};
//矩阵乘法
Matrix mul(Matrix a, Matrix b)
{
    Matrix ans;
    for (int i = 0; i < maxn; ++i)
    {
        for (int j = 0; j < maxn; ++j)
        {
            ans.a[i][j] = 0;
            for (int k = 0; k < maxn; ++k)
            {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod;
            }
        }
    }
    return ans;
}
//矩阵快速幂
Matrix qpow(Matrix a, int n)
{
    Matrix ans;
    ans.init();
    while (n)
    {
        if (n & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        n /= 2;
    }
    return ans;
}
16000000000000000000
18446744073709551616
int main()
{
    Matrix a;
    a.a[0][0] = a.a[0][1] = a.a[1][1] = a.a[1][2] = a.a[1][3] = a.a[2][2] =a.a[2][3] =a.a[3][0] =a.a[3][1] = a.a[3][3]=0;
    a.a[0][2] = a.a[1][0] = a.a[2][0] = a.a[3][2] = 1;
    a.a[0][3] = 2;
    a.a[2][1] = 3;
    int n;
    scanf("%d", &n);
    printf("%lld\n",qpow(a, n - 2));
    system("pause");
    return 0;
}