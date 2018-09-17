#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int l;
int flag = 0;
int cnt = 0;
char b[10250];
long long ans = 0;
long long n = 0;
int work(int o, char *O, int I)
{
	char c, *D = O;
	if (o > 0)
	{
		for (l = 0; D[l]; D[l++] -= 10)
		{
			D[l++] -= 120;
			D[l] -= 110;
			while (!work(0, O, l))
				D[l] += 20;
			//putchar((D[l] + 1032) / 20);
			b[++cnt] = (D[l] + 1032) / 20;
			if (flag == 0)
			{
				ans = ans * 10 + b[cnt] - '0';
				if (ans > sqrt(n))
				{
					flag = cnt - 1;
				}
			}
			//system("pause");
		}
		putchar(10);
		b[++cnt] = '1';
		if (flag == 0)
		{
			ans = ans * 10 + b[cnt] - '0';
			if (ans > sqrt(n))
			{
				flag = cnt - 1;
			}
		}
		b[++cnt] = '0';
		if (flag == 0)
		{
			ans = ans * 10 + b[cnt] - '0';
			if (ans > sqrt(n))
			{
				flag = cnt - 1;
			}
		}
	}
	else
	{
		c = o + (D[I] + 82) % 10 - (I > l / 2) * (D[I - l + I] + 72) / 10 - 9;
		D[I] += I < 0 ? 0 : !(o = work(c / 10, O, I - 1)) * ((c + 999) % 10 - (D[I] + 92) % 10);
	}
	return o;
}

int main()
{
	char s[1200];
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		s[0] = '0';
		scanf("%s", s + 1);
		int l = strlen(s);
		n = 0;
		for (int i = 1; i <= l; i++)
		{
			n = n * 10 + s[i] - '0';
		}
		for (int i = 1; i <= 200; i++)
		{
			s[l + 1] = '0';
		}
		s[l + 200] = '\0';
		if (strlen(s) % 2 == 1)
		{
			work(2, s + 1, 0);
		}
		else
		{
			work(2, s, 0);
		}
		for (int i = 1; i <= cnt;i++)
		{
			printf("%c", b[i]);
			if(flag==i)
				printf(".");
		}
	}
	return 0;
}