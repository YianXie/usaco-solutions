#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; ++i)
        cin >> cows[i];

    if (n == 2) {
        if (cows[0] == cows[1]) {
            cout << cows[0] << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    set<int> ans;
    for (int i = 0; i < n - 2; ++i) {
        if (cows[i] == cows[i + 1] || cows[i] == cows[i + 2]) {
            ans.insert(cows[i]);
        } else if (cows[i + 1] == cows[i + 2]) {
            ans.insert(cows[i + 1]);
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        int idx = 0;
        for (const int& i : ans) {
            cout << i;
            if (idx < ans.size() - 1)
                cout << " ";
            ++idx;
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}