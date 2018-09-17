#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
/*从这里开始都是版子~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
const int MAXN=105;
long long mod=9223372036854775807LL;                                            //模除值，不需要请删除
struct mat
{
	int line;                                                                   //矩阵的行
	int row;                                                                    //矩阵的列
	long long a[MAXN][MAXN];                                                          //值
	mat(int n=0,int m=0,long long p=0)                                              //构造一个n行m列，斜对角线为p的矩阵
	{
		line=n;
		row=m;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i)
		{
			a[i][i]=p;
		}
	}
};
mat operator *(const mat &x,const mat &y)                                                     //重载矩阵乘法
{
	mat ans;
	for(int i=1;i<=x.line;++i)
	{
		for(int j=1;j<=y.row;++j)
		{
			ans.a[i][j]=0;
			for(int k=1;k<=x.row;++k)
			{
				ans.a[i][j]=(ans.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
			}
		}
	}
	ans.line=x.line;
	ans.row=y.row;
	return ans;
}
void operator *=(mat &x,mat y)
{
	x=x*y;
}
mat quickpow(mat A,long long x)                                                       //矩阵快速幂,求A的x次幂。
{
	mat ans(A.line,A.row,1);
	while(x)
	{

		if(x&1)
		{
			ans*=A;
		}
		A*=A;
		x>>=1;
	}
	return ans;
}
void scans(mat &A)
{
    scanf("%d %d",&A.line,&A.row);
    for(int i=1;i<=A.line;++i)
    {
        for(int j=1;j<=A.row;++j)
        {
            scanf("%lld",&A.a[i][j]);
        }
    }
}
void prints(const mat &A)
{
    printf("%d %d\n",A.line,A.row);
    for(int i=1;i<=A.line;++i)
    {
        for(int j=1;j<=A.row;++j)
        {

            j==A.row?printf("%d\n",A.a[i][j]):printf("%d ",A.a[i][j]);
        }
    }
}
bool can_multiplication(const mat &A,const mat &B)
{
    return A.row==B.line;
}
/*版子结束的地方~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
mat A,B;
int main()
{
    scans(A);
    scans(B);
    if(can_multiplication(A,B))
    {
        prints(A*B);
    }
    else
    {
        printf("Error: %d != %d\n",A.row,B.line);
    }
	system("pause");
	return 0;
}
