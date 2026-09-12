#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Temperature {
    ll low, high;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("milktemp.in", "r", stdin);
    freopen("milktemp.out", "w", stdout);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    vector<ll> rawTemps(2 * n);
    vector<ll> lowTemps(n);
    vector<ll> highTemps(n);
    for (int i = 0; i < 2 * n; i += 2) {
        ll low, high;
        cin >> low >> high;
        rawTemps[i] = low;
        rawTemps[i + 1] = high;
        lowTemps[i / 2] = low;
        highTemps[i / 2] = high;
    }

    vector<ll> uniqueTemps;
    uniqueTemps = rawTemps;
    uniqueTemps.push_back(-1);
    uniqueTemps.push_back(1e9 + 1);
    sort(uniqueTemps.begin(), uniqueTemps.end());
    uniqueTemps.erase(unique(uniqueTemps.begin(), uniqueTemps.end()), uniqueTemps.end());

    sort(lowTemps.begin(), lowTemps.end());
    sort(highTemps.begin(), highTemps.end());

    ll ans = 0;
    for (const ll& temp : uniqueTemps) {
        ll tempAns = 0;
        int numLower = n - (upper_bound(lowTemps.begin(), lowTemps.end(), temp) - lowTemps.begin());
        int numHigher = lower_bound(highTemps.begin(), highTemps.end(), temp) - highTemps.begin();
        tempAns += x * numLower;
        tempAns += y * (n - numLower - numHigher);
        tempAns += z * numHigher;
        ans = max(ans, tempAns);
    }

    cout << ans << "\n";
    return 0;
}