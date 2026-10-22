#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
map<ll, ll> intervals;

bool check(ll d)
{
    ll pos = intervals.begin()->first;
    for (int placed = 1; placed < n; ++placed) {
        ll target = pos + d;
        auto nxt = intervals.upper_bound(target);
        auto cur = prev(nxt);

        if (cur->second >= target) {
            pos = target;
        } else if (nxt != intervals.end()) {
            pos = nxt->first;
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        intervals[a] = b;
    }

    ll low = 1, high = 1e18;
    ll mid;
    while (low < high) {
        mid = low + (high - low + 1) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << "\n";
    return 0;
}