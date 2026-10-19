#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> cows;

bool check(int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> temp(n);
    for (int i = 0; i < k; ++i) {
        pq.push(cows[i]);
        temp[i] = cows[i];
    }

    for (int i = k; i < n; ++i) {
        temp[i] = pq.top() + cows[i];
        if (temp[i] > t) {
            return false;
        }
        pq.pop();
        pq.push(temp[i]);
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> n >> t;

    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }

    int low = 1, high = n;
    int mid, ans;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (check(mid)) {
            high = mid;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}