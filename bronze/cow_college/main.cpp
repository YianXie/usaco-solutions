#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> budget(n);
    for (int i = 0; i < n; ++i)
        cin >> budget[i];
    sort(budget.begin(), budget.end());

    ll ans = 0;
    int fee;
    for (int i = 0; i < n; ++i) {
        ll profit = budget[i] * (n - i);
        if (profit > ans) {
            ans = profit;
            fee = budget[i];
        }
    }

    cout << ans << " " << fee << endl;
    return 0;
}