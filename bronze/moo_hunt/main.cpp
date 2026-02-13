#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<vector<int>>> frequency(n, vector<vector<int>>(n, vector<int>(n)));
    for (int i = 0; i < k; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        ++frequency[x - 1][y - 1][z - 1];
    }

    int best = -1;
    int cnt = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int current = 0;

        // 0 - O, 1 - M
        vector<int> Ms;
        vector<int> Os;
        for (int i = 0; i < n; ++i) {
            if ((1 << i) & mask) {
                Ms.push_back(i);
            } else {
                Os.push_back(i);
            }
        }

        for (int& m : Ms) {
            for (int i = 0; i < Os.size(); ++i) {
                for (int j = 0; j < Os.size(); ++j) {
                    if (j == i)
                        continue;
                    current += frequency[m][Os[i]][Os[j]];
                }
            }
        }
        if (current > best) {
            best = current;
            cnt = 1;
        } else if (current == best) {
            ++cnt;
        }
    }

    cout << best << " " << cnt << endl;
    return 0;
}