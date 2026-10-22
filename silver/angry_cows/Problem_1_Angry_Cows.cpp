#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> bales;

bool check(int r)
{
    int left = 0;
    int numCows = 0;
    while (left < n) {
        if (numCows >= k) {
            return false;
        }
        int right = upper_bound(bales.begin(), bales.end(), bales[left] + 2 * r) - bales.begin() - 1;
        numCows++;
        left = right + 1;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> n >> k;

    bales.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> bales[i];
    }
    sort(bales.begin(), bales.end());

    int low = 0, high = 1e9;
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << "\n";
    return 0;
}