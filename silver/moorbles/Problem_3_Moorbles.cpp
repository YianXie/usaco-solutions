#include <bits/stdc++.h>
using namespace std;

struct Turn {
    int maxEven = 0;
    int maxOdd = 0;
    int minEven = 1001;
    int minOdd = 1001;
    bool isAllEven = false;
    bool isAllOdd = true;
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> marbles(m, vector<int>(k));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> marbles[i][j];
        }
    }

    int loss = 0;
    vector<string> ans(m);
    vector<int> minN(m + 1, INT_MAX);
    vector<int> lossN(m);
    vector<Turn> turns(m);
    for (int i = 0; i < m; ++i) {
        int maxEven = 0;
        int maxOdd = 0;
        int minEven = 1001;
        int minOdd = 1001;
        bool isAllOdd = true;
        bool isAllEven = true;
        for (int j = 0; j < k; ++j) {
            int val = marbles[i][j];
            if (val % 2 == 0) {
                isAllOdd = false;
                maxEven = max(maxEven, val);
                minEven = min(minEven, val);
            } else {
                isAllEven = false;
                maxOdd = max(maxOdd, val);
                minOdd = min(minOdd, val);
            }
        }
        turns[i] = { maxEven, maxOdd, minEven, minOdd, isAllEven, isAllOdd };

        if (isAllEven) {
            loss -= minEven;
            ans[i] = "Even";
        } else if (isAllOdd) {
            loss -= minOdd;
            ans[i] = "Odd";
        } else {
            loss += min(maxEven, maxOdd);
            if (maxEven > maxOdd) {
                ans[i] = "Even";
            } else {
                ans[i] = "Odd";
            }
        }
        lossN[i] = n - loss;

        if ((n - loss) <= 0) {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = m - 1; i >= 0; --i) {
        minN[i] = min(minN[i + 1], lossN[i]);
    }

    loss = 0;
    for (int i = 0; i < m; ++i) {
        if (ans[i] == "Even") {
            continue;
        }

        loss += turns[i].maxOdd;
        if (turns[i].isAllOdd) {
            loss += turns[i].minOdd;
        } else {
            loss -= turns[i].maxEven;
        }

        if ((minN[i] - loss) > 0) {
            ans[i] = "Even";
        } else {
            loss -= turns[i].maxOdd;
            if (turns[i].isAllOdd) {
                loss -= turns[i].minOdd;
            } else {
                loss += turns[i].maxEven;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i];
        if (i < (m - 1)) {
            cout << " ";
        }
    }
    cout << "\n";
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