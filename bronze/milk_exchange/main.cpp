#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod(ll k, ll n)
{
    return ((k % n) + n) % n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    string str;
    cin >> n >> m >> str;

    vector<ll> volumes(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> volumes[i];
        ans += volumes[i];
    }

    for (int i = 0; i < n; ++i) {
        if (str[i] == 'R' && str[(i + 1) % n] == 'L') {
            ll rSum = 0;
            int rIdx = (i - 1) % n;
            while (str[rIdx] == 'R') {
                rSum += volumes[rIdx];
                --rIdx;
                rIdx = mod(rIdx, n);
            }

            ll lSum = 0;
            int lIdx = (i + 2) % n;
            while (str[lIdx] == 'L') {
                lSum += volumes[lIdx];
                ++lIdx;
                lIdx = mod(lIdx, n);
            }

            ans -= min(m, rSum);
            ans -= min(m, lSum);
        }
    }

    cout << ans << endl;
    return 0;
}