#include <bits/stdc++.h>
using namespace std;

set<int> ans;
void solve(vector<int> barn1, vector<int> barn2, int day, int remaining)
{
    if (day >= 4) {
        ans.insert(remaining);
        return;
    }
    if (day % 2 == 0) {
        for (const int& bucket : barn1) {
            vector<int> barn1Copy = barn1;
            vector<int> barn2Copy = barn2;
            barn1Copy.erase(find(barn1Copy.begin(), barn1Copy.end(), bucket));
            barn2Copy.push_back(bucket);
            solve(barn1Copy, barn2Copy, day + 1, remaining - bucket);
        }
    } else {
        for (const int& bucket : barn2) {
            vector<int> barn1Copy = barn1;
            vector<int> barn2Copy = barn2;
            barn1Copy.push_back(bucket);
            barn2Copy.erase(find(barn2Copy.begin(), barn2Copy.end(), bucket));
            solve(barn1Copy, barn2Copy, day + 1, remaining + bucket);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> barn1;
    vector<int> barn2;
    for (int i = 0; i < 10; ++i) {
        int num;
        cin >> num;
        barn1.push_back(num);
    }
    for (int i = 0; i < 10; ++i) {
        int num;
        cin >> num;
        barn2.push_back(num);
    }

    solve(barn1, barn2, 0, 1000);
    cout << ans.size() << endl;

    return 0;
}