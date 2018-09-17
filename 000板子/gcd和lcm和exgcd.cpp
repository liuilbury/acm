int gcd(int x,int y)//最大公约数
{
	while(y!=0)
	{
		int t=y;
		y=x%y;
		x=t;
	}
	return x;
}
int lcm(int x,int y)//最小公倍数
{
	return x/gcd(x,y)*y;
}
long long exgcd(long long a,long long b,long long &x,long long &y)//拓展gcd
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long r = exgcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - a / b * y;
	return r;
}