#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int n;
vector<Point> cows;

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

bool check(int x)
{
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((cows[j].x - cows[i].x) * (cows[j].x - cows[i].x) + (cows[j].y - cows[i].y) * (cows[j].y - cows[i].y) <= x) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int counter = 0;
    dfs(graph, 0, visited, counter);
    return counter == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> n;

    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cows[i] = { x, y };
    }

    int low = 0, high = 2e9;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << "\n";
    return 0;
}