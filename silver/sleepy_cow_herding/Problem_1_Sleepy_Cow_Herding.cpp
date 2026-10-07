#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    // min
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(cows.begin(), cows.end(), cows[i] + n - 1) - cows.begin() - 1;
        int numInPlace = j - i + 1;
        if (cows[j] - cows[i] + 1 == n || numInPlace < n - 1) {
            ans = min(ans, n - numInPlace);
        } else {
            ans = min(ans, n - numInPlace + 1);
        }
    }
    cout << ans << "\n";

    // max
    if (cows.back() - cows[n - 2] < cows[1] - cows.front()) {
        cout << (cows[n - 2] - cows.front() - 1) - (n - 3) << "\n";
    } else {
        cout << (cows.back() - cows[1] - 1) - (n - 3) << "\n";
    }

    return 0;
}