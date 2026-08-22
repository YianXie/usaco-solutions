#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> field(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> field[i][j];
        }
    }

    vector<vector<int>> ps(n, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            ps[i][j] = ps[i][j - 1] + field[i][j - 1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int first_row = max(0, i - k);
            int last_row = min(n - 1, i + k);
            int temp = 0;
            for (int row = first_row; row <= last_row; ++row) {
                int left = max(0, j - (k - abs(row - i)));
                int right = min(n - 1, j + (k - abs(row - i)));
                temp += ps[row][right + 1] - ps[row][left];
            }
            ans = max(ans, temp);
        }
    }

    cout << ans << endl;
    return 0;
}