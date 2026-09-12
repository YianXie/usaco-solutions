#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n;
    cin >> n;

    vector<Cow> cows(n);
    vector<int> xs;
    xs.reserve(n);

    for (int i = 0; i < n; ++i) {
        cin >> cows[i].x >> cows[i].y;
        xs.push_back(cows[i].x);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    int ans = n;
    vector<int> byY(n);
    iota(byY.begin(), byY.end(), 0);
    sort(byY.begin(), byY.end(),
        [&](int a, int b) { return cows[a].y < cows[b].y; });

    for (const int& vx : xs) {
        const int x = vx + 1;

        vector<int> side(n);
        int aboveLeft = 0;
        int aboveRight = 0;
        int belowLeft = 0;
        int belowRight = 0;
        for (int i = 0; i < n; ++i) {
            if (cows[i].x < x) {
                side[i] = 0;
                aboveLeft++;
            } else {
                side[i] = 1;
                aboveRight++;
            }
        }

        for (int idx = 0; idx < n; ++idx) {
            int id = byY[idx];
            if (side[id] == 0) {
                --aboveLeft;
                ++belowLeft;
            } else {
                --aboveRight;
                ++belowRight;
            }

            if (idx < n - 1 && cows[byY[idx]].y != cows[byY[idx + 1]].y) {
                ans = min(ans, max({ aboveLeft, aboveRight, belowLeft, belowRight }));
            }
        }
    }

    cout << ans << "\n";
    return 0;
}