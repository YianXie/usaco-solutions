#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> stones(n);
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
    }
    sort(stones.begin(), stones.end());

    vector<int> pre(n + 1), suf(n + 1);
    int preBest = 0, sufBest = 0;
    for (int i = 0; i < n; ++i) {
        int newPreLength = i - (lower_bound(stones.begin(), stones.end(), stones[i] - k) - stones.begin()) + 1;
        int newSufLength = (upper_bound(stones.begin(), stones.end(), stones[n - i - 1] + k) - stones.begin() - 1) - (n - i - 1) + 1;
        preBest = max(preBest, newPreLength);
        sufBest = max(sufBest, newSufLength);
        pre[i + 1] = preBest;
        suf[n - i - 1] = sufBest;
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, pre[i] + suf[i]);
    }

    cout << ans << "\n";
    return 0;
}