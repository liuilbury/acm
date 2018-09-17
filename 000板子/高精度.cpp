#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1500;
struct bign
{
	int num[MAXN];
	int l;
	int sig;
	bign(long long n = 0)
	{
		memset(num, 0, sizeof(num));
		if (n)
		{
			l = 0;
			if (n < 0)
			{
				sig = 1;
				n *= -1;
			}
			else
				sig = 0;
			while (n)
			{
				num[++l] = n % 10;
				n /= 10;
			}
		}
		else
		{
			l = 1;
			sig = 0;
		}
	}
	bign(char s[])
	{
		char stk[MAXN];
		int top = 0;
		int ls = strlen(s);
		int i = 0;
		l = 0;
		for (int i = 0; i < MAXN; ++i)
		{
			num[i] = 0;
		}
		if (s[i] == '-')
		{
			sig = 1;
			++i;
		}
		else if (s[i] == '+')
		{
			sig = 0;
			++i;
		}
		else
		{
			sig = 0;
		}
		for (; i < ls; ++i)
		{
			stk[++top] = s[i];
		}
		while (top)
		{
			num[++l] = stk[top--] - '0';
		}
		while (num[l] == 0 && l > 1)
			--l;
	}
};
int max1(int a1, int b1)
{
	return a1 > b1 ? a1 : b1;
}
int min1(int a1, int b1)
{
	return a1 < b1 ? a1 : b1;
}

bool operator<(bign a1, bign b1);
bool operator>(bign a1, bign b1);
bool operator==(bign a1, bign b1);
bool operator!=(bign a1, bign b1);
bool operator>=(bign a1, bign b1);
bool operator<=(bign a1, bign b1);
bign operator+(bign a1, bign b1);
bign operator-(bign a1, bign b1);
bign operator*(bign a1, bign b1);
bign operator/(bign a1, bign b1);
bign operator%(bign a1, bign b1);
void scans(bign &a1);
void prints(bign a1);
bign bigabs(bign a1);
bign bigroot(bign a1, int b1); //¿ªn´Î·½¸ù£»
bign biggcd(bign x, bign y);
bign bigpow(bign x, int y);
bool operator<(bign a1, bign b1)
{
	if (a1.sig ^ b1.sig)
	{
		return a1.sig ? true : false;
	}
	if (a1.sig)
	{
		return bigabs(a1) > bigabs(b1);
	}
	if (a1.l != b1.l)
		return a1.l < b1.l;
	for (int i = a1.l; i; --i)
	{
		if (a1.num[i] != b1.num[i])
			return a1.num[i] < b1.num[i];
	}
	return false;
}
bool operator>(bign a1, bign b1)
{
	if (a1.sig ^ b1.sig)
	{
		return a1.sig ? false : true;
	}
	if (a1.sig)
	{
		return bigabs(a1) < bigabs(b1);
	}
	if (a1.l != b1.l)
		return a1.l > b1.l;
	for (int i = a1.l; i; --i)
	{
		if (a1.num[i] != b1.num[i])
			return a1.num[i] > b1.num[i];
	}
	return false;
}
bool operator>=(bign a1, bign b1)
{
	return !(a1 < b1);
}
bool operator<=(bign a1, bign b1)
{
	return !(a1 > b1);
}
bool operator==(bign a1, bign b1)
{
	if (a1.sig != b1.sig || a1.l != b1.l)
		return false;
	for (int i = a1.l; i; --i)
	{
		if (a1.num[i] != b1.num[i])
			return false;
	}
	return true;
}
bool operator!=(bign a1, bign b1)
{
	return !(a1 == b1);
}
bign operator+(bign a1, bign b1)
{
	if (a1.sig ^ b1.sig)
	{
		if (a1.sig)
		{
			a1.sig ^= 1;
			return b1 - a1;
		}
		else
		{
			b1.sig ^= 1;
			return a1 - b1;
		}
	}
	a1.l = max1(a1.l, b1.l) + 1;
	for (int i = 1; i <= a1.l; i++)
	{
		a1.num[i] += b1.num[i];
		if (a1.num[i] >= 10)
		{
			a1.num[i + 1] += a1.num[i] / 10;
			a1.num[i] %= 10;
		}
	}
	while (a1.num[a1.l] == 0 && a1.l > 1)
		--a1.l;
	return a1;
}
bign operator-(bign a1, bign b1)
{
	if (a1.sig ^ b1.sig)
	{
		b1.sig ^= 1;
		return a1 + b1;
	}
	if (bigabs(b1) > bigabs(a1))
	{
		bign c1 = b1 - a1;
		c1.sig ^= 1;
		return c1;
	}
	a1.l = max1(a1.l, b1.l);
	for (int i = 1; i <= a1.l; i++)
	{
		a1.num[i] -= b1.num[i];
		if (a1.num[i] < 0)
		{
			a1.num[i] += 10;
			a1.num[i + 1] -= 1;
		}
	}
	while (a1.num[a1.l] == 0 && a1.l > 1)
		--a1.l;
	if (a1.l == 1 && a1.num[1] == 0)
		a1.sig = 0;
	return a1;
}
bign operator*(bign a1, bign b1)
{
	bign c1;
	c1.l = a1.l + b1.l;
	c1.sig = a1.sig ^ b1.sig;
	for (int i = 1; i <= a1.l; ++i)
	{
		for (int j = 1; j <= b1.l; ++j)
		{
			c1.num[i + j - 1] += a1.num[i] * b1.num[j];
		}
	}
	for (int i = 1; i <= c1.l; ++i)
	{
		if (c1.num[i] >= 10)
		{
			c1.num[i + 1] += c1.num[i] / 10;
			c1.num[i] %= 10;
		}
	}
	while (c1.num[c1.l] == 0 && c1.l > 1)
		--c1.l;
	if (c1.l == 1 && c1.num[1] == 0)
		c1.sig = 0;
	return c1;
}
bign operator/(bign a1, bign b1)
{
	bign c1, d1, ten = bign(10LL);
	c1.sig = a1.sig ^ b1.sig;
	b1.sig = 0;
	c1.l = a1.l;
	for (int i = a1.l; i >= 1; --i)
	{
		d1 = d1 * ten;
		d1.num[1] = a1.num[i];
		while (d1 >= b1)
		{
			d1 = d1 - b1;
			++c1.num[i];
		}
	}
	while (c1.num[c1.l] == 0 && c1.l > 1)
		--c1.l;
	if (c1.l == 1 && c1.num[1] == 0)
		c1.sig = 0;
	return c1;
}
bign operator%(bign a1, bign b1)
{
	bign c1, d1, ten = bign(10LL);
	b1.sig = 0;
	c1.l = a1.l;
	for (int i = a1.l; i >= 1; --i)
	{
		d1 = d1 * ten;
		d1.num[1] = a1.num[i];
		while (d1 >= b1)
		{
			d1 = d1 - b1;
			++c1.num[i];
		}
	}
	d1.sig = a1.sig;
	while (d1.num[d1.l] == 0 && d1.l > 1)
		--d1.l;
	if (d1.l == 1 && d1.num[1] == 0)
		d1.sig = 0;
	return d1;
}
bign bigabs(bign a1)
{
	a1.sig = 0;
	return a1;
}
void prints(bign a1)
{
	if (a1.sig)
	{
		printf("-");
	}
	for (int i = a1.l; i; --i)
	{
		printf("%d", a1.num[i]);
	}
}
void scans(bign &a1)
{
	char temp[MAXN];
	scanf("%s", &temp);
	a1 = bign(temp);
	if (a1.l == 1 && a1.num[1] == 0)
		a1.sig = 0;
}
bign biggcd(bign x, bign y)
{
	bign zero = bign(0LL);
	while (y != zero)
	{
		bign t = y;
		y = x % y;
		x = t;
	}
	return x;
}
bign bigpow(bign x, int y)
{
	bign ans = bign(1);
	while (y)
	{
		if (y & 1)
			ans = ans * x;
		x = x * x;
		y >>= 1;
	}
	return ans;
}
bign bigroot(bign a1, int b1)
{
	int pow10 = a1.l % b1 ? a1.l / b1 : a1.l / b1 - 1;
	bign l = bigpow(bign(10), pow10);
	bign r = bigpow(bign(10), pow10 + 1);
	while (l != r)
	{
		bign mid = (l + r) / bign(2);
		if (bigpow(mid, b1) >= a1)
		{
			r = mid;
		}
		else
		{
			l = mid + bign(1);
		}
	}
	return bigpow(l, b1) <= a1 ? l : l - bign(1);
}
int T;
char a[100000], b[100000], c[100000];
bign f1, f2, f3, g;
bign cnt;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", &a);
        int l = strlen(a);
        int flag = 0;
        for (int i = 0; i < l; i++)
        {
            if (flag == 0)
            {
                if ((a[i] - '0') % 2 == 0)
                {
                    b[i] = a[i];
                    c[i] = a[i];
                }
                else
                {
                    flag = 1;
                    b[i] = a[i] - 1;
                    c[i] = a[i] + 1;
                }
            }
            else
            {
                b[i] = '8';
                c[i] = '0';
            }
        }
        int flag2 = 0;
        f1 = bign(a);
        f2 = bign(b);
        f3 = BigNum(c);
        if (f3 - f1 > f1 - f2)
        {
            flag2 = 1;
        }
        else
            flag2 = 0;
        flag = 0;
        if (flag2 == 0)
        {
            for (int i = 0; i < l; i++)
            {
                if (flag == 0 && b[i] == '0')
                    continue;
                else
                {
                    printf("%c", b[i]);
                    flag = 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < l; i++)
            {
                if (flag == 0 && c[i] == '0')
                    continue;
                else
                {
                    printf("%c", c[i]);
                    flag = 1;
                }
            }
        }
        printf("\n");
    }
}