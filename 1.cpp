#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, n, m;
    char b[20] = {"AC"};
    char c[20] = {"CE"};
    char a[200];
    scanf("%d", &T);
    for (int i = 1; i <= T;i++)
    {
        int sum=0,t=0;
        scanf("%d",&n);
        int flag = 0;
        for (int j = 1; j <= n;j++)
        {
            scanf("%s", &a);
            if(flag==0)
            {
            if(strcmp(a,b)==0)
            {
                flag = 1;
                t = sum;
            }
            else if(strcmp(a,c)==0)
            {
                continue;
            }
            else
                sum += 20;
            }
        }
        if(flag==0)
            printf("-1\n");
        else
            printf("%d\n", t);
    }
        return 0;
}