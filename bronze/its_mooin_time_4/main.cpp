#include <bits/stdc++.h>
using namespace std;

int t, k;

void solve()
{
    int n;
    string str;
    cin >> n >> str;

    cout << "YES" << endl;

    string ans(n, 'O');
    int numO = 0;
    for (int i = n - 1; i >= 0; --i) {
        char target = str[i];
        if (numO % 2 == 1) {
            target = target == 'O' ? 'M' : 'O';
        }

        numO += target == 'O';
        ans[i] = target;
    }

    if (k == 1)
        cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> k;

    while (t--) {
        solve();
    }

    return 0;
}