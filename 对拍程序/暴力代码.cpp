#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int tmp; scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    int diff = INT_MAX;
    int ans = -1;
    for (auto v : vec) {
        if (v >= k) {
            if (v - k < diff) {
                ans = v;
                // diff = v - k;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}