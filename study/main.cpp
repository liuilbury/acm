#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m;
    long long sum;
    while (cin >> n >> m)
    {
        int t = (int)sqrt(m);
        sum = m * n;
        if (n > m)
            n = m;
        for (int i = 1; i <= t; i++)
        {
            sum -= i * (min(m / i, n) + min(m / (i + 1), n) + 1) * (min(m / i, n) - min(m / (i + 1), n)) / 2;
            if (i == t && i * i == m)
                continue;
            sum -= (m / i) * (m / (m / i),n + (m / ((m / i) + 1) + 1) * (min(m / (m / i),n) - min(m / ((m / i) + 1),n)) / 2;
        }
        cout << sum << endl;
    }
}
//20
//1 2 3 4 5
//4 2 1 1 0