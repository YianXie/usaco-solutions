#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        ll distance;
        char direction;
        cin >> distance >> direction;
        if (direction == 'L') {
            distance *= -1;
        }
        pre[i + 1] = pre[i] + distance;
    }

    vector<ll> endpoints;
    endpoints = pre;
    sort(endpoints.begin(), endpoints.end());
    endpoints.erase(unique(endpoints.begin(), endpoints.end()), endpoints.end());

    vector<ll> diff(endpoints.size());
    for (int i = 0; i < n; ++i) {
        int left = lower_bound(endpoints.begin(), endpoints.end(), min(pre[i], pre[i + 1])) - endpoints.begin();
        int right = lower_bound(endpoints.begin(), endpoints.end(), max(pre[i], pre[i + 1])) - endpoints.begin();
        diff[left]++;
        diff[right]--;
    }

    vector<ll> ansPre(diff.size() + 1);
    for (int i = 1; i <= diff.size(); ++i) {
        ansPre[i] = ansPre[i - 1] + diff[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < ansPre.size(); ++i) {
        if (ansPre[i] >= k) {
            ans += endpoints[i] - endpoints[i - 1];
        }
    }

    cout << ans << "\n";
    return 0;
}