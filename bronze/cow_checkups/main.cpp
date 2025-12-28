#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cows(n);
    vector<int> species(n);

    for (int i = 0; i < n; ++i)
        cin >> cows[i];
    for (int i = 0; i < n; ++i)
        cin >> species[i];

    vector<bool> pre(n);
    int same = 0;
    for (int i = 0; i < n; ++i) {
        pre[i] = cows[i] == species[i];
        same += cows[i] == species[i];
    }

    vector<int> ans(n + 1, 0);
    for (int c = 0; c < n; ++c) {
        int prev = same;
        for (int i = 0; i <= min(c, n - c - 1); ++i) {
            prev -= pre[c + i];
            prev += cows[c + i] == species[c - i];
            prev -= pre[c - i];
            prev += cows[c - i] == species[c + i];
            ans[prev]++;
        }
    }
    for (int c = 0; c < n - 1; ++c) {
        int prev = same;
        for (int i = 0; i <= min(c, n - c - 2); ++i) {
            prev -= pre[c + i + 1];
            prev += cows[c + i + 1] == species[c - i];
            prev -= pre[c - i];
            prev += cows[c - i] == species[c + i + 1];
            ans[prev]++;
        }
    }

    for (const int& a : ans)
        cout << a << endl;

    return 0;
}