#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> vec;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int pos = lower_bound(vec.begin(), vec.end(), k) - vec.begin();
    int ans = pos == vec.size() ? -1 : vec[pos];
    printf("%d\n", ans);

    return 0;
}