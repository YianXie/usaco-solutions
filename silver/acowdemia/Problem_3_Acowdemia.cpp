#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, l;
vector<int> papers;

bool check(int h)
{
    int idx = lower_bound(papers.begin(), papers.end(), h) - papers.begin() - 1;
    if (idx == -1) {
        return true;
    }
    int numNeeded = h - (n - idx - 1);
    if (numNeeded <= 0) {
        return true;
    }

    ll total = 0;
    for (int i = idx; i >= idx - numNeeded + 1; --i) {
        total += h - papers[i];
    }
    return k >= h - papers[idx - numNeeded + 1] && k * l >= total && k * l >= numNeeded;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> l;

    papers.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> papers[i];
    }
    sort(papers.begin(), papers.end());

    int low = 1, high = n;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << "\n";
    return 0;
}