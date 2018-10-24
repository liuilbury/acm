#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main()
{
    int T;
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
    {
        int x, y, n;
        scanf("%d%d%d", &n, &x, &y);
        if (n == 0)
        {
            printf("No winner\n");
            continue;
        }
        int flag = false;
        int res = 0;
        if (x > y)
            swap(x, y), flag = true;
        if (x == 1)
        {
            if (y == 1)
                res = 0;
            if (y == 2)
                res = n % 3 == 2 ? 1 : 0;
            if (y == 3)
                res = n == 1 ? 0 : -1;
            if (y == 4)
                res = n == 1 ? 0 : 1;
            if (y == 5)
                res = -1;
            if (y == 6)
                res = 0;
            if (y == 7)
            {
                if (n < 20)
                    res = 1;
                if (n == 20)
                    res = 0;
                if (n > 20)
                    res = -1;
            }
        }
        if (x == 2)
        {
            if (y == 2)
                res = 0;
            if (y == 3)
                res = n == 1 ? 0 : 1;
            if (y == 4)
                res = 0;
            if (y == 5)
                res = n % 3 == 1 ? -1 : 0;
            if (y == 6)
                res = n == 1 ? 0 : -1;
            if (y == 7)
            {
                if (n <= 10)
                {
                    res = n % 3 == 0 ? 0 : 1;
                }
                if (n == 11)
                    res = 0;
                if (n > 11)
                    res = -1;
            }
        }
        if (x == 3)
        {
            if (y == 3)
                res = 0;
            if (y == 4)
                res = n == 1 ? 0 : -1;
            if (y == 5)
            {
                if (n == 1)
                    res = -1;
                if (n == 2)
                    res = 0;
                if (n > 2)
                    res = 1;
            }
            if (y == 6)
                res = n == 1 ? 0 : 1;
            if (y == 7)
            {
                if (n < 30)
                    res = 1;
                if (n == 30 || n == 31)
                    res = 0;
                if (n >= 32)
                    res = -1;
            }
        }
        if (x == 4)
        {
            if (y == 4)
                res = 0;
            if (y == 5)
                res = -1;
            if (y == 6)
                res = n == 1 ? 0 : -1;
            if (y == 7)
            {
                if (n == 1)
                    res = 1;
                if (n == 2)
                    res = 0;
                if (n > 2)
                    res = -1;
            }
        }
        if (x == 5)
        {
            if (y == 5)
                res = 0;
            if (y == 6)
                res = 1;
            if (y == 7)
                res = -1;
        }
        if (x == 6)
        {
            if (y == 6)
                res = 0;
            if (y == 7)
            {
                if (n <= 10)
                    res = 1;
                if (n == 11 || n == 12)
                    res = 0;
                if (n >= 13)
                    res = -1;
            }
        }
        //  printf("res:%d\n",res);
        if (flag == true)
            res *= -1;
        if (res == -1)
            printf("Winner b\n");
        if (res == 0)
            printf("No winner\n");
        if (res == 1)
            printf("Winner a\n");
    }
}