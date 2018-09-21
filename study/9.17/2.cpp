#include<bits/stdc++.h>
using namespace std;
int map1[105][105];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    if(n==1||m==1)
    {
        
    }
    if(n%2==1&&m%2==1)
        return 1;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            scanf("%d", map1[i][j]);
        }
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(map1[i+1][j+1])
        }
    }
}
