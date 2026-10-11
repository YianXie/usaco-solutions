#include <bits/stdc++.h>
using namespace std;

struct Record {
    int day, id, change;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n, g;
    cin >> n >> g;

    vector<Record> records(n);
    for (int i = 0; i < n; ++i) {
        int day, id, change;
        cin >> day >> id >> change;
        records[i] = { day, id, change };
    }
    sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
        return a.day < b.day;
    });

    int ans = 0;
    map<int, int> cows;
    map<int, set<int>> leaderboard = { { g, { (int)1e9 + 1 } } };
    for (const Record& record : records) {
        if (!cows.count(record.id)) {
            cows[record.id] = g;
            leaderboard[g].insert(record.id);
        }
        auto before = *leaderboard.rbegin();
        auto it = leaderboard.find(cows[record.id]);
        it->second.erase(record.id);
        if (it->second.empty()) {
            leaderboard.erase(it);
        }
        cows[record.id] += record.change;
        leaderboard[cows[record.id]].insert(record.id);
        auto after = *leaderboard.rbegin();
        ans += before.second != after.second;
    }

    cout << ans << "\n";
    return 0;
}