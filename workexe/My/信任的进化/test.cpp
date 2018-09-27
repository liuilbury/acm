#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 5000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
int main()
{
    //freopen("1.txt", "r", stdin);
    //reopen("2.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b, n;
        scanf("%d %d %d", &n, &a, &b);
        //cout << n<<' '<<a << ' ' << b << endl;
        if (n==0)
        {
            printf("No winer\n");
            continue;
        }
        if (a == 1 && b == 2)
        {
            if ((n - 2) % 3 == 0)
                printf("Winer a\n");
            else
                printf("No winer\n");
        }
        else if (a == 2 && b == 1)
        {
            if ((n - 2) % 3 == 0)
                printf("Winer b\n");
            else
                printf("No winer\n");
        }
        else if (a == 1 && b == 3)
        {
            if (n == 1 || n == 0)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 3 && b == 1)
        {
            if (n == 1 || n == 0)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 1 && b == 4)
        {
            if (n == 1 || n == 0)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 4 && b == 1)
        {
            if (n == 1 || n == 0)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 1 && b == 5)
        {
            printf("Winer b\n");
        }
        else if (a == 5 && b == 1)
        {
            printf("Winer a\n");
        }
        else if (a == 1 && b == 6)
        {
            printf("No winer\n");
        }
        else if (a == 6 && b == 1)
        {
            printf("No winer\n");
        }
        else if (a == 1 && b == 7)
        {
            if (n <= 19)
            {
                printf("Winer a\n");
            }
            else if (n == 20)
            {
                printf("No winer\n");
            }
            else
                printf("Winer b\n");
        }
        else if (a == 7 && b == 1)
        {
            if (n <= 19)
            {
                printf("Winer b\n");
            }
            else if (n == 20)
            {
                printf("No winer\n");
            }
            else
                printf("Winer a\n");
        }
        else if (a == 2 && b == 3)
        {
            printf("No winer\n");
        }
        else if (a == 3 && b == 2)
        {
            printf("No winer\n");
        }
        else if (a == 2 && b == 4)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 4 && b == 2)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 2 && b == 5)
        {
            if ((n - 1) % 3 == 0)
                printf("Winer b\n");
            else
                printf("No winer\n");
        }
        else if (a == 5 && b == 2)
        {
            if ((n - 1) % 3 == 0)
                printf("Winer a\n");
            else
                printf("No winer\n");
        }
        else if (a == 2 && b == 6)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 6 && b == 2)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 2 && b == 7)
        {
            if (n <= 10)
            {
                if (n % 3 == 0)
                    printf("No winer\n");
                else
                    printf("Winer a\n");
            }
            else if (n == 11)
            {
                printf("No winer\n");
            }
            else
            {
                printf("Winer b\n");
            }
        }
        else if (a == 7 && b == 2)
        {
            if (n <= 10)
            {
                if (n % 3 == 0)
                    printf("No winer\n");
                else
                    printf("Winer b\n");
            }
            else if (n == 11)
            {
                printf("No winer\n");
            }
            else
            {
                printf("Winer a\n");
            }
        }
        else if (a == 3 && b == 4)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 4 && b == 3)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 3 && b == 5)
        {
            if (n == 1)
                printf("Winer b\n");
            else if (n == 2)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 5 && b == 3)
        {
            if (n == 1)
                printf("Winer a\n");
            else if (n == 2)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 3 && b == 6)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 6 && b == 3)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 3 && b == 7)
        {
            if (n <= 29)
                printf("Winer a\n");
            else if (n == 30 || n == 31)
            {
                printf("No winer\n");
            }
            else
                printf("Winer b\n");
        }
        else if (a == 7 && b == 3)
        {
            if (n <= 29)
                printf("Winer b\n");
            else if (n == 30 || n == 31)
            {
                printf("No winer\n");
            }
            else
                printf("Winer a\n");
        }
        else if (a == 4 && b == 5)
        {
            printf("Winer b\n");
        }
        else if (a == 5 && b == 4)
        {
            printf("Winer a\n");
        }
        else if (a == 4 && b == 6)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 6 && b == 4)
        {
            if (n == 1)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 4 && b == 7)
        {
            if (n == 1)
                printf("Winer a\n");
            else if (n == 2)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 7 && b == 4)
        {
            if (n == 1)
                printf("Winer b\n");
            else if (n == 2)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
        else if (a == 5 && b == 6)
        {
            printf("Winer a\n");
        }
        else if (a == 6 && b == 5)
        {
            printf("Winer b\n");
        }
        else if (a == 5 && b == 7)
        {
            printf("Winer b\n");
        }
        else if (a == 7 && b == 5)
        {
            printf("Winer a\n");
        }
        else if (a == 6 && b == 7)
        {
            if (n <= 10)
                printf("Winer a\n");
            else if (n == 11 || n == 12)
                printf("No winer\n");
            else
                printf("Winer b\n");
        }
        else if (a == 7 && b == 6)
        {
            if (n <= 10)
                printf("Winer b\n");
            else if (n == 11 || n == 12)
                printf("No winer\n");
            else
                printf("Winer a\n");
        }
    }
}