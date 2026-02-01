#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> heights(n);
    vector<ll> canes(m);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];
    for (int i = 0; i < m; ++i)
        cin >> canes[i];

    for (const ll& cane : canes) {
        ll lowest = 1;
        for (int i = 0; i < n; ++i) {
            if (lowest > cane)
                break;
            if (heights[i] >= lowest) {
                int prev = heights[i];
                heights[i] += min(cane - lowest + 1, heights[i] - lowest + 1);
                lowest += heights[i] - prev;
            }
        }
    }

    for (const ll& height : heights)
        cout << height << endl;

    return 0;
}