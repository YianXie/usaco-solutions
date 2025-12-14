#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    int n, m;
    fin >> n >> m;

    vector<pair<int, int>> graph(m);
    vector<int> colors(n);
    for (int i = 0; i < m; ++i) {
        fin >> graph[i].first >> graph[i].second;
    }

    for (int i = 1; i <= n; ++i) {
        set<int> neighbors;
        for (const auto& pair : graph) {
            if (pair.first == i)
                neighbors.insert(colors[pair.second - 1]);
            else if (pair.second == i)
                neighbors.insert(colors[pair.first - 1]);
        }
        for (int j = 1; j <= 4; ++j) {
            if (!neighbors.count(j)) {
                colors[i - 1] = j;
                break;
            }
        }
    }

    for (const int& c : colors)
        fout << c;

    return 0;
}