#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> stations;

bool bfs(int target, int destination)
{
    queue<int> queue;
    set<int> visited;
    queue.push(destination);
    while (!queue.empty()) {
        int val = queue.front();
        queue.pop();
        if (val == target)
            return true;
        else if (val && !visited.count(val)) {
            visited.insert(val);
            queue.push(stations[val - 1]);
        }
    }
    return false;
}

bool ok(int target)
{
    vector<bool> results(n, false);
    results[target - 1] = true;

    for (int i = 1; i <= n; ++i) {
        if (i != target)
            if (bfs(target, stations[i - 1]))
                results[i - 1] = true;
    }
    for (const bool& result : results)
        if (!result)
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    cin >> n;
    stations.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        stations[a - 1] = b;
    }

    for (int i = 1; i <= n; ++i) {
        if (ok(i)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}