#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<ll> months;
    for (int i = 0; i < n; ++i) {
        ll month;
        cin >> month;
        months.insert(month);
    }

    ll ans = 0;
    if (months.size() <= 3) {
        ans = (1 + *months.begin() / 4) * (*months.begin() / 4) / 2;
    } else {
        set<ll> diff;
        vector<ll> monthsVec(months.begin(), months.end());
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                diff.insert(abs(monthsVec[i] - monthsVec[j]));
            }
        }

        set<ll> divisors;
        for (const ll& i : diff) {
            ll j = 1;
            while (j * j <= i) {
                if (i % j == 0) {
                    divisors.insert(j);
                    divisors.insert(i / j);
                }
                j++;
            }
        }

        for (const ll& i : divisors) {
            if (i > (*months.begin() / 4)) {
                break;
            }
            set<ll> uniqueRemainders;
            bool ok = true;
            for (const ll& j : months) {
                uniqueRemainders.insert(j % i);
                if (uniqueRemainders.size() > 3) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += i;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}