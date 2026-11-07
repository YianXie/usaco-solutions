#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> removed;

void dfs(const int& node, vector<bool>& visited)
{
    visited[node] = true;
    for (const int& i : graph[node]) {
        if (!visited[i] && !removed[i]) {
            dfs(i, visited);
        }
    }
}

bool isConnected()
{
    vector<bool> visited(n + 1, false);
    bool multipleComponents = false;
    for (int i = 1; i <= n; ++i) {
        if (!removed[i] && !visited[i]) {
            if (multipleComponents) {
                return false;
            }
            dfs(i, visited);
            multipleComponents = true;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> n >> m;

    removed.resize(n + 1);
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int b1, b2;
        cin >> b1 >> b2;
        graph[b1].push_back(b2);
        graph[b2].push_back(b1);
    }

    if (isConnected()) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    for (int i = 0; i < n - 1; ++i) {
        int b;
        cin >> b;
        removed[b] = true;
        if (isConnected()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}