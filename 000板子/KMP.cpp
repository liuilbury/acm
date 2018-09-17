#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=200005;
char a[MAXN],b[MAXN];
int fail[MAXN],ans;
bool success[MAXN];
void getfail(char t[],int fail[])
{
	fail[0]=fail[1]=0;int l=strlen(t);
	for(int i=1;i<l;++i)
	{
		int j=fail[i];
		while(j&&t[i]!=t[j])j=fail[j];
		fail[i+1]=t[j]==t[i]?j+1:0;
	}
}
int MP(char s[],char t[],int fail[])
{
	int j=0;int l1=strlen(s);int l2=strlen(t);
	for(int i=0;i<l1;++i)
	{
		while(j&&s[i]!=t[j])j=fail[j];
		if(s[i]==t[j])++j;
        if(j==l2)
            return j;
        if(i==l1-1)return j;
	}
}
int l1,l2;
int main()
{
    while(scanf("%s %s",&a,&b)!=EOF)
    {
        int t = strlen(a);
        for (int i = t; i <= 2 * t - 1;i++)
        {
            a[i] = a[i - t];
        }
        a[2 * t] = '\0';
        getfail(b, fail);
        l1=MP(a,b,fail);
        if(l1==strlen(b))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
