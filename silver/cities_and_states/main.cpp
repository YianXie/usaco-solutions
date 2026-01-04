#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n;
    cin >> n;

    long long ans = 0;
    map<string, map<string, long long>> cnt;
    for (int i = 0; i < n; ++i) {
        string city, state;
        cin >> city >> state;
        const string c = city.substr(0, 2);

        if (c != state) {
            ans += cnt[state][c];
        }
        ++cnt[c][state];
    }

    cout << ans << endl;
    return 0;
}