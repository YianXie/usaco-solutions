#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int n, m;
vector<Point> cows;
vector<vector<int>> graph;

void dfs(const int& node, vector<bool>& visited, int& left, int& right, int& top, int& bottom)
{
    visited[node] = true;
    left = min(left, cows[node].x);
    right = max(right, cows[node].x);
    top = max(top, cows[node].y);
    bottom = min(bottom, cows[node].y);
    for (const int& i : graph[node]) {
        if (!visited[i]) {
            dfs(i, visited, left, right, top, bottom);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    cin >> n >> m;

    cows.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        cows[i] = { x, y };
    }

    graph.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = INT_MAX;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int left = INT_MAX, right = INT_MIN, top = INT_MIN, bottom = INT_MAX;
            dfs(i, visited, left, right, top, bottom);
            ans = min(ans, (right - left) * 2 + (top - bottom) * 2);
        }
    }

    cout << ans << "\n";
    return 0;
}