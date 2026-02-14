#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> subs = {
    { "MOM", 1 },
    { "MOO", 0 },
    { "OOM", 2 },
    { "OOO", 1 }
};

void solve()
{
    string str;
    cin >> str;

    if (str.size() < 3) {
        cout << -1 << endl;
        return;
    }

    int best = str.size();
    bool found = false;
    for (int i = 0; i < str.size() - 2; ++i) {
        const string sub = str.substr(i, 3);
        if (subs.count(sub)) {
            found = true;
            int current = subs[sub] + (str.size() - 3);
            best = min(best, current);
        }
    }

    if (!found) {
        cout << -1 << endl;
    } else {
        cout << best << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        solve();
    }

    return 0;
}