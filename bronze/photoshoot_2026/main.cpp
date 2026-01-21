#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    int best = 0;
    vector<vector<int>> field(n, vector<int>(n));
    vector<vector<int>> graph(n - k + 1, vector<int>(n - k + 1));
    for (int i = 0; i < q; ++i) {
        int row, col, value;
        cin >> row >> col >> value;
        int diff = value - field[row - 1][col - 1];
        field[row - 1][col - 1] = value;
        for (int x = max(0, row - k); x <= min(n - k, n - k - (n - row - k + 1)); ++x) {
            for (int y = max(0, col - k); y <= min(n - k, n - k - (n - col - k + 1)); ++y) {
                graph[x][y] += diff;
                if (graph[x][y] > best) {
                    best = graph[x][y];
                }
            }
        }
        cout << best << endl;
    }

    return 0;
}