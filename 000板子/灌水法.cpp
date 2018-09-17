char map[25][25];
int vis[25][25];
int w,h,x,y,k,q,sx,sy,i,cnt;
char a,b,c,d;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
void flood(int x,int y)
{
    int i;
    vis[y][x]=1;
    cnt++;
    for(i=0;i<4;++i)
    {
        if(x+dx[i]>=0&&x+dx[i]<w&&y+dy[i]>=0&&y+dy[i]<h)
        {
            if(vis[y+dy[i]][x+dx[i]]==0)
            {
                if(map[y+dy[i]][x+dx[i]]=='.')
                {
                    flood(x+dx[i],y+dy[i]);
                }
            }
        }
    }
}
