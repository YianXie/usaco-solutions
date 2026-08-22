#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
        cows[i] %= 7;
    }

    vector<int> ps(n + 1);
    for (int i = 1; i <= n; ++i) {
        ps[i] = ps[i - 1] + cows[i - 1];
        ps[i] %= 7;
    }

    int ans = 0;
    for (int i = 0; i < 7; ++i) {
        int first = -1;
        for (int j = 0; j < n; ++j) {
            if (ps[j] == i) {
                first = j;
                break;
            }
        }

        int last = -1;
        if (first != -1) {
            for (int j = n - 1; j >= 0; --j) {
                if (ps[j] == i) {
                    last = j;
                    break;
                }
            }
        }

        if (first != -1 && last != -1 && first != last) {
            ans = max(ans, last - first);
        }
    }

    cout << ans << endl;
    return 0;
}