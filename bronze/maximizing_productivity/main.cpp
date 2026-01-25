#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> farms(n);
    vector<int> weights(n);

    for (int i = 0; i < n; ++i)
        cin >> farms[i];

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        weights[i] = farms[i] - num;
    }

    sort(weights.begin(), weights.end());

    while (q--) {
        int v, s;
        cin >> v >> s;

        auto it = upper_bound(weights.begin(), weights.end(), s);
        if (it != weights.end()) {
            if (weights.end() - it >= v) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}