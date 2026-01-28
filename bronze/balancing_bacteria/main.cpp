#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> fields(n);
    for (int i = 0; i < n; ++i)
        cin >> fields[i];

    for (int i = n - 1; i >= 1; --i) {
        fields[i] -= fields[i - 1];
    }

    ll ans = abs(fields[0]);
    for (int i = 1; i < n; ++i) {
        ans += abs(fields[i] - fields[i - 1]);
    }

    cout << ans << endl;
    return 0;
}