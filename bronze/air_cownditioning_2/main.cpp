#include <bits/stdc++.h>
using namespace std;

struct AirCon {
    int start, end, temperature, cost;

    bool operator==(const AirCon& other) const
    {
        return std::tie(start, end, temperature, cost) == std::tie(other.start, other.end, other.temperature, other.cost);
    }
};

int n, m;
vector<int> stalls(100);
vector<AirCon> aircons;
int ans = INT_MAX;

bool goalTest(vector<AirCon> aircons)
{
    vector<int> result(100);
    for (const AirCon& aircon : aircons) {
        for (int i = aircon.start; i <= aircon.end; ++i) {
            result[i - 1] += aircon.temperature;
        }
    }
    for (int i = 0; i < 100; ++i) {
        if (result[i] < stalls[i])
            return false;
    }
    return true;
}

void solve(vector<AirCon> prev, int start)
{
    int totalCost = 0;
    for (const AirCon& aircon : prev) {
        totalCost += aircon.cost;
    }
    if (totalCost > ans)
        return;

    if (goalTest(prev)) {
        ans = totalCost;
        return;
    }
    for (int i = start; i < m; ++i) {
        const AirCon& aircon = aircons[i];
        if (find(prev.begin(), prev.end(), aircon) != prev.end())
            continue;
        vector<AirCon> prevCopy = prev;
        prevCopy.push_back(aircon);
        solve(prevCopy, i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    aircons.resize(m);
    for (int i = 0; i < n; ++i) {
        int start, end, temperature;
        cin >> start >> end >> temperature;
        for (int j = start; j <= end; ++j) {
            stalls[j - 1] = temperature;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> aircons[i].start >> aircons[i].end >> aircons[i].temperature >> aircons[i].cost;
    }
    solve({}, 0);

    cout << ans << endl;

    return 0;
}