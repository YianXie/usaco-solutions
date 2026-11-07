#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x, y, p;
};

void dfs(const vector<vector<int>>& graph, const int& node, vector<bool>& visited, int& counter)
{
    visited[node] = true;
    counter++;
    for (const int& i : graph[node]) {
        if (!visited[i]) {
            dfs(graph, i, visited, counter);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;

    vector<Cow> cows(n);
    for (int i = 0; i < n; ++i) {
        int x, y, p;
        cin >> x >> y >> p;
        cows[i] = { x, y, p };
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int distance = (cows[j].x - cows[i].x) * (cows[j].x - cows[i].x) + (cows[j].y - cows[i].y) * (cows[j].y - cows[i].y);
            if (distance <= cows[i].p * cows[i].p) {
                graph[i].push_back(j);
            }
        }
    }

    int best = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        fill(visited.begin(), visited.end(), false);
        int counter = 0;
        dfs(graph, i, visited, counter);
        best = max(best, counter);
    }

    cout << best << "\n";
    return 0;
}