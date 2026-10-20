#include <bits/stdc++.h>
using namespace std;

int n, m, c;
vector<int> cows;

bool check(int t)
{
    int idx = 0, numBuses = 0;
    while (idx < n) {
        if (numBuses >= m) {
            return false;
        }
        if (cows[min(n - 1, idx + c - 1)] - cows[idx] <= t) {
            idx = min(n - 1, idx + c - 1) + 1;
            numBuses++;
        } else {
            int j = upper_bound(cows.begin(), cows.end(), cows[idx] + t) - cows.begin() - 1;
            idx = j + 1;
            numBuses++;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;

    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    int low = 0, high = cows.back() - cows.front();
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << "\n";
    return 0;
}