#include<bits/stdc++.h>
using namespace std;
char IN_FILE[20];
char OUT_FILE[20];
char USER_ANS[20];
char USER_SRC[20];
int res,ures,a[1005][1005],n,m,ans,x;
map<int,int >mp;
bool ck(int x,int y) {
    if(x%2==y%2)return 0;
    return 1;
}
int main() {

    scanf("%d",&ans);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            scanf("%d",&x),mp[x]++;
        }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            scanf("%d",&a[i][j]);
            if(i==1&&j==1&&ans==-1&&a[1][1]!=-1)return -1;
            mp[a[i][j]]--;
            if(mp[a[i][j]]<0)return -1;
        }
    if(ck(a[1][2],a[2][1])==0)return -1;
    if(ck(a[1][m-1],a[2][m])==0)return -1;
    if(ck(a[n-1][1],a[n][2])==0)return -1;
    if(ck(a[n-1][m],a[n][m-1])==0)return -1;
    for(int j=2; j<=m-1; j++)if(ck(a[2][j],a[1][j+1])==0||ck(a[2][j],a[1][j-1])==0)return -1;
    for(int j=2; j<=m-1; j++)if(ck(a[n-1][j],a[n][j+1])==0||ck(a[n-1][j],a[n][-1])==0)return -1;
    for(int i=2; i<=n-1; i++)if(ck(a[i-1][1],a[i][2])==0||ck(a[i][2],a[i+1][1])==0)return -1;
    for(int i=2; i<=n-1; i++)if(ck(a[i-1][m],a[i][m-1])==0||ck(a[i][m-1],a[i+1][m])==0)return -1;

    for(int i=2; i<=n-1; i++) {
        for(int j=2; j<=m-1; j++) {
            if(ck(a[i+1][j],a[i][j+1])==0)return -1;
            if(ck(a[i+1][j],a[i][j-1])==0)return -1;
            if(ck(a[i-1][j],a[i][j+1])==0)return -1;
            if(ck(a[i-1][j],a[i][j-1])==0)return -1;
        }
    }

    return 0;
}
