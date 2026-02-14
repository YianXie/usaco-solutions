#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> price(N);
    for (int i = 0; i < N; i++)
        cin >> price[i];

    for (int i = 1; i < N; i++) {
        price[i] = min(price[i], price[i - 1] * 2);
    }

    const int MAX = min(N - 1, 30);

    ll bestHuge = 1LL * 1e18;
    for (int i = 31; i < N; i++)
        bestHuge = min(bestHuge, price[i]);

    while (Q--) {
        ll x;
        cin >> x;

        ll ans = bestHuge;
        ll current = 0;
        ll remaining = x;

        for (int i = MAX; i >= 0; i--) {
            ll quantity = 1LL << i;

            ll take = remaining / quantity;
            current += take * price[i];
            remaining -= take * quantity;

            if (remaining > 0)
                ans = min(ans, current + price[i]);
            else
                ans = min(ans, current);
        }

        cout << ans << endl;
    }

    return 0;
}
