#include <bits/stdc++.h>
using namespace std;

bool isSquare(string str)
{
    if (str.size() % 2 != 0)
        return false;

    for (int i = 0; i < str.size() / 2 - 1; ++i) {
        if (str[i] != str[i + str.size() / 2])
            return false;
    }
    return true;
}

void solve()
{
    int n;
    string str;
    cin >> n >> str;

    if (n % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    if (isSquare(str)) {
        cout << 1 << endl;
        for (int i = 0; i < n * 3; ++i) {
            cout << 1;
            if (i < n * 3 - 1)
                cout << " ";
        }
        cout << endl;
        return;
    }

    vector<int> ans(n * 3, 2);
    for (int i = 0; i < str.size() / 2 - 1; i += 3) {
        const string sub1 = str.substr(i, 3);
        const string sub2 = str.substr(i + n * 3 / 2, 3);
        if (sub1.substr(0, 2) == sub2.substr(0, 2)) {
            ans[i] = 1;
            ans[i + 1] = 1;
            ans[i + n * 3 / 2] = 1;
            ans[i + n * 3 / 2 + 1] = 1;
        } else if (sub1.substr(0, 2) == sub2.substr(1, 2)) {
            ans[i] = 1;
            ans[i + 1] = 1;
            ans[i + n * 3 / 2 + 1] = 1;
            ans[i + n * 3 / 2 + 2] = 1;
        } else if (sub1.substr(1, 2) == sub2.substr(0, 2)) {
            ans[i + 1] = 1;
            ans[i + 2] = 1;
            ans[i + n * 3 / 2] = 1;
            ans[i + n * 3 / 2 + 1] = 1;
        } else {
            ans[i + 1] = 1;
            ans[i + 2] = 1;
            ans[i + n * 3 / 2 + 1] = 1;
            ans[i + n * 3 / 2 + 2] = 1;
        }
    }

    cout << 2 << endl;
    for (int i = 0; i < n * 3; ++i) {
        cout << ans[i];
        if (i < n * 3 - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;

    while (t--) {
        solve();
    }

    return 0;
}