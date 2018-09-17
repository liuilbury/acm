int n, m;
int dp[1000000];
int w[1010], v[1010], num[1010],all;
//多重背包的二进制优化  V-背包总容量 cost-单件物品花费(重量)  amount-单件物品数量  weight-单件物品价值
void zero(int cost,int weight)
{
    for(int i=all;i>=cost;i--)
    dp[i]=max(dp[i],dp[i-cost]+weight);
}
void complet(int cost,int weight)
{
    for(int i=cost;i<=all;i++)
    dp[i]=max(dp[i],dp[i-cost]+weight);
}
void multi(int cost ,int amount ,int weight)
{
    if(cost*amount>=all)
    {
        complet(cost,weight);
        return;
       }
       int k=1;
       while(k<amount)
       {
        zero(k*cost,k*weight);
        amount-=k;
        k=k*2;
    }
    zero(amount*cost,amount*weight);
}


struct Queue//V-背包最大容量  c[i]第i种物品数量  v[i]第i种物品价值  w[i]第i种物品重量  注意定义全局变量
{
    int num,value;
}que[250005];
int head,tail;
void enqueue (int x,int y)
{
    while (head<=tail && que[tail].value<y) tail--;
    que[++tail].num=x;que[tail].value=y;
}
void multipack()
{
    int i,j,d;
    memset(dp,0,sizeof(dp));
    for (i=1 ; i<=n ; ++i)
    {
        if (c[i] > V/w[i]) c[i]=V/w[i];
        for (d=0 ; d<w[i] ; ++d)
        {
            head=1;tail=0;
            for (j=0 ; j<=(V-d)/w[i] ; ++j)
            {
                enqueue(j , dp[j*w[i]+d]-j*v[i]);
                while (que[head].num<j-c[i] && head<=tail) head++;
                dp[j*w[i]+d]=que[head].value+j*v[i];
            }
        }
    }
}  //单调队列优化模板