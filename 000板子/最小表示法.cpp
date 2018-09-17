#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
const int MAXN=100055;
char s[MAXN];
int n;
string ss;
set<string> cnt;
int Min(char s[])
{
    int l=strlen(s);
    int p1=0;int p2=1;
    while(p1<l&&p2<l)
    {
        int k=0;
        while(k<l&&s[(p1+k)%l]==s[(p2+k)%l])++k;
        if(k>=l)break;
        if(s[(p1+k)%l]>s[(p2+k)%l])
        {
            p1=p1+k+1;
        }
        else
        {
            p2=p2+k+1;
        }
        if(p1==p2)++p2;
    }
    return p1<p2?p1:p2;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        cnt.clear();
        for(int t=1;t<=n;++t)
        {
            scanf("%s",&s);
            ss.clear();
            int l=strlen(s);
            int p=Min(s);
            for(int i=0;i<l;++i)
            {
                ss+=s[(p+i)%l];
            }
            cnt.insert(ss);
        }
        printf("%d\n",cnt.size());
    }
    return 0;
}
