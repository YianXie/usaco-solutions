#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n < 45) {
            cout << 0 << endl;
            continue;
        }

        string int_string = to_string(n);
        long long minimum = 5, maximum = 0;
        long long ans = 0;
        for (int i = 1; i < int_string.size(); ++i) {
            minimum += 4 * pow(10, i);
            maximum = pow(10, i + 1) / 2 - 1;
            ans += max(0LL, min(n, maximum) - minimum + 1);
        }
        cout << ans << endl;
    }

    return 0;
}