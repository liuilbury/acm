#include<cstring>
#include<iostream>
#include<cstdio>
int pow(int n, int time)
{
    int ans = 1;
    for (int i = 1; i <= time; i++)
        ans *= n;
    return ans;
}

int change_any_to_10(char *s, int type)
{
    int ans = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            ans += (s[i] - '0') * pow(type, len - 1 - i);
        else if (s[i] >= 'a' && s[i] <= 'z')
            ans += (s[i] - 'a' + 10) * pow(type, len - 1 - i);
        else if (s[i] >= 'A' && s[i] <= 'Z')
            ans += (s[i] - 'A' + 10) * pow(type, len - 1 - i);
    }
    return ans;
}

/**********************************************
十进制  转 任意进制

注意： j 是标记数组有多少个元素 输出时以
            for(int i=0;i<j;i++)
                printf("%c",s[i]);

        输出，以puts(s); 或 printf("%s",s); 输出
        前面计算的数组长度会影响后面结果
**********************************************/

char s[1000];
int j;
void change_10_to_any(int old, int type)
{
    j = 0;
    if (old)
    {
        change_10_to_any(old / type, type);
        s[j++] = old % type > 9 ? old % type - 10 + 'A' : old % type + '0';
    }
}
int main()
{
    int n, b, c;
    char a[20000];
    while(scanf("%d",&n)!=EOF)
    {
        int sum = 0;
        for (int i = 1; i <= n;i++)
        {
            int flag = 0;
            c = 0;
            scanf("%s", &a);
            int l = strlen(a);
            for (int i = 0; i < l;i++)
            {
                if(a[i]=='(')
                {
                    a[i] = '\0';
                    flag = 1;
                }
                else if(flag==1&&a[i]>='0'&&a[i]<='9')
                    c = c * 10 + a[i] - '0';
            }
            //printf("%s %d\n", a, c);
            sum += change_any_to_10(a, c);
        }
        printf("%d\n", sum);
    }
}