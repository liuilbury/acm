#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
	while(y!=0)
	{
		long long t=y;
		y=x%y;
		x=t;
	}
	return x;
}
long long lcm(long long x,long long y)
{
	return x/gcd(x,y)*y;
}
struct fraction
{
    long long n1,n2;
    int sign;
    fraction (long long _n1=0,long long _n2=1)
    {
        n1=abs(_n1);
        n2=abs(_n2);
        if(_n1==0)
        {
            sign=0;
        }
        else
        {
            sign=(_n1<0)^(_n2<0);
        }
    }
    long long get_int()
    {
        return sign?-(n1/n2):n1/n2;
    }
    double get_double()
    {
        return sign?-(double(n1)/double(n2)):double(n1)/double(n2);
    }
};

void reduction_fraction(fraction &x);
void reduction_fractions_common(fraction &x,fraction &y);
fraction get_reciprocal(fraction x);
fraction fraction_abs(fraction x);
fraction operator + (fraction x, fraction y);
fraction operator - (fraction x, fraction y);
fraction operator * (fraction x, fraction y);
fraction operator / (fraction x, fraction y);
bool operator == (fraction x, fraction y);
bool operator != (fraction x, fraction y);
bool operator > (fraction x, fraction y);
bool operator < (fraction x, fraction y);
bool operator >= (fraction x, fraction y);
bool operator <= (fraction x, fraction y);

void reduction_fraction(fraction &x)
{
    if(!x.n1)
    {
        x.n2=1;
        x.sign=0;
        return;
    }
    long long temp=gcd(x.n1,x.n2);
    x.n1/=temp;
    x.n2/=temp;
}

void reduction_fractions_common(fraction &x,fraction &y)
{
    long long _lcm=lcm(x.n2,y.n2);
    x.n1=x.n1*(_lcm/x.n2);
    y.n1=y.n1*(_lcm/y.n2);
    x.n2=_lcm;
    y.n2=_lcm;
}

fraction get_reciprocal(fraction x)
{
    fraction ans;
    ans.sign=x.sign;
    ans.n1=x.n2;
    ans.n2=x.n1;
    return ans;
}

fraction fraction_abs(fraction x)
{
    x.sign=0;
    return x;
}

fraction operator + (fraction x,fraction y)
{
    if(x.sign^y.sign)
	{
		if(x.sign)
		{
			x.sign^=1;
			return y-x;
		}
		else
		{
			y.sign^=1;
			return x-y;
		}
	}
	fraction ans;
	ans.sign=x.sign;
	reduction_fractions_common(x,y);
	ans.n1=x.n1+y.n1;
	ans.n2=x.n2;
	reduction_fraction(ans);
	return ans;
}

fraction operator - (fraction x,fraction y)
{
    if(x.sign^y.sign)
	{
		y.sign^=1;
		return x+y;
	}
	fraction ans;
	ans.sign=x.sign;
	reduction_fractions_common(x,y);
	ans.n1=x.n1-y.n1;
	ans.n2=x.n2;
	if(ans.n1<0)
    {
        ans.sign^=1;
        ans.n1=abs(ans.n1);
    }
    reduction_fraction(ans);
    return ans;
}

fraction operator * (fraction x,fraction y)
{
    fraction ans;
    ans.sign=x.sign^y.sign;
    ans.n1=x.n1*y.n1;
    ans.n2=x.n2*y.n2;
    reduction_fraction(ans);
    return ans;
}

fraction operator / (fraction x,fraction y)
{
    return x*get_reciprocal(y);
}

bool operator == (fraction x,fraction y)
{
    reduction_fraction(x);
    reduction_fraction(y);
    return (x.sign==y.sign&&x.n1==y.n1&&x.n2==y.n2);
}

bool operator != (fraction x,fraction y)
{
    return !(x==y);
}

bool operator > (fraction x,fraction y)
{
    if(x.sign^y.sign)
	{
		return x.sign?false:true;
	}
	if(x.sign)
	{
		return fraction_abs(x)<fraction_abs(y);
	}
	reduction_fraction(x);
	reduction_fraction(y);
	reduction_fractions_common(x,y);
	return x.n1>y.n1;
}

bool operator <(fraction x,fraction y)
{
    if(x.sign^y.sign)
	{
		return x.sign?true:false;
	}
	if(x.sign)
	{
		return fraction_abs(x)>fraction_abs(y);
	}
	reduction_fraction(x);
	reduction_fraction(y);
	reduction_fractions_common(x,y);
	return x.n1<y.n1;
}

bool operator >= (fraction x,fraction y)
{
    return !(x<y);
}

bool operator <= (fraction x,fraction y)
{
    return !(x>y);
}

void scans(fraction &x)
{
    scanf("%lld/%lld",&x.n1,&x.n2);
}

void prints(fraction x)
{
    if(x.sign)
    {
        printf("-");
    }
    if(x.n1==0)
    {
        printf("0");
        return;
    }
    if(x.n2==1)
    {
        printf("%lld",x.n1);
        return;
    }
    printf("%lld/%lld",x.n1,x.n2);
}
int main()
{
    int n;
    fraction a, b;
    scanf("%d", &n);
    scans(a);
    fraction sum;
    sum = a;
    for (int i = 2; i <= n;i++)
    {
        scans(a);
        sum = sum + a;
    }
        prints(sum*fraction (1,n));
    return 0;
}
