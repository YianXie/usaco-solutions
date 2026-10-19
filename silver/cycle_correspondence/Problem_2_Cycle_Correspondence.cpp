#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans = 0;
set<int> uniqueBarns;
map<int, int> aBarns;
map<int, int> bBarns;

void solve()
{
    vector<int> arr(k);
    for (const auto& [val, idx] : bBarns) {
        auto it = aBarns.find(val);
        if (it != aBarns.end()) {
            if (idx <= it->second) {
                arr[it->second - idx]++;
            } else {
                arr[k - (idx - it->second)]++;
            }
        }
    }
    int best = 0;
    for (const int& i : arr) {
        best = max(best, i);
    }
    ans = max(ans, (int)(n - uniqueBarns.size()) + best);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        aBarns[a] = i;
        uniqueBarns.insert(a);
    }
    for (int i = 0; i < k; ++i) {
        int b;
        cin >> b;
        bBarns[b] = i;
        uniqueBarns.insert(b);
    }

    solve();
    for (const auto& [key, value] : bBarns) {
        bBarns[key] = k - bBarns[key] - 1;
    }
    solve();

    cout << ans << "\n";
    return 0;
}