int bol[1000005];
void su()
{
    int i,b,j;
    for(i=2;i<=1000001;i++)
        bol[i]=1;
    i=0;b=2;
    bol[1]=0;
    for(i=2;i<1001;i++)
    {
        for(j=i*i;j<=1000001;j=j+i)
        {
            bol[j]=0;
        }
    }
}
