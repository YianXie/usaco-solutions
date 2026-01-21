#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long a, b, ca, cb, fa;
        cin >> a >> b >> ca >> cb >> fa;

        if ((b / cb) * ca + a >= fa) {
            cout << 0 << endl;
            continue;
        }

        long long remaining = fa - a - (b / cb) * ca;
        b %= cb;

        long long ans = 0;
        if (cb > ca) {
            long long cbs = ((remaining + ca - 1) / ca - 1) * cb + cb - b - 1;
            ans += cbs;
            ans += remaining - (cbs - cb + 1 + b) / cb * ca;
        } else {
            ans += remaining - 1;
            ans += cb - b;
        }
        cout << ans << endl;
    }

    return 0;
}