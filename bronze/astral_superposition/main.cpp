#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<char>> photo(n);
    vector<vector<char>> stars(n, vector<char>(n, '#'));

    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j)
            photo[i].push_back(row[j]);
    }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (photo[row][col] == 'B') {
                int otherRow = row - b;
                int otherCol = col - a;
                if ((otherRow < 0 || otherCol < 0) || (photo[otherRow][otherCol] == 'W')) {
                    cout << -1 << endl;
                    return;
                }
                stars[row][col] = '.';
                stars[otherRow][otherCol] = '.';
            }
        }
    }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (photo[row][col] == 'G' && stars[row][col] != '.') {
                int otherRow = row - b;
                int otherCol = col - a;
                if (((otherRow < 0 || otherCol < 0)) || (stars[otherRow][otherCol] != '.'))
                    stars[row][col] = '.';
            }
        }
    }

    int ans = 0;
    for (int row = 0; row < n; ++row)
        for (int col = 0; col < n; ++col)
            ans += stars[row][col] == '.';

    cout << ans << endl;
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