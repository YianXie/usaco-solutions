#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<int> ids(n);
    for (int i = 0; i < n; ++i)
        cin >> ids[i];

    vector<array<int, 3>> pre(n + 1, { 0, 0, 0 });
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i];
        pre[i + 1][ids[i] - 1]++;
    }

    while (q--) {
        int left, right;
        cin >> left >> right;
        cout << pre[right][0] - pre[left - 1][0] << " "
             << pre[right][1] - pre[left - 1][1] << " "
             << pre[right][2] - pre[left - 1][2] << "\n";
    }

    return 0;
}