#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll x, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n;
    cin >> n;

    vector<Node> cows(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        cows[i] = { x, y };
    }
    sort(cows.begin(), cows.end(), [](Node& a, Node& b) {
        return a.y < b.y;
    });

    ll ans = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        if (cows[left].x < cows[right].x) {
            ans = max(ans, cows[left].y + cows[right].y);
            cows[right].x -= cows[left].x;
            left++;
        } else if (cows[left].x == cows[right].x) {
            ans = max(ans, cows[left].y + cows[right].y);
            left++;
            right--;
        } else {
            ans = max(ans, cows[left].y + cows[right].y);
            cows[left].x -= cows[right].x;
            right--;
        }
    }
    if (left == right) {
        ans = max(ans, cows[left].y * 2);
    }

    cout << ans << "\n";
    return 0;
}