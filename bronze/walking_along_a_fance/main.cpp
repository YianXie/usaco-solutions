#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;

    vector<vector<int>> graph(1001, vector<int>(1001));
    vector<pair<int, int>> points(p);
    for (int i = 0; i < p; ++i)
        cin >> points[i].first >> points[i].second;

    int perimeter = 0;
    for (int i = 0; i < p; ++i) {
        int nextI = (i + 1) % p;
        if (points[i].first == points[nextI].first) {
            for (int j = points[i].second; j != points[nextI].second; j += (points[nextI].second > points[i].second ? 1 : -1)) {
                graph[j][points[i].first] = perimeter;
                ++perimeter;
            }
        } else {
            for (int j = points[i].first; j != points[nextI].first; j += (points[nextI].first > points[i].first ? 1 : -1)) {
                graph[points[i].second][j] = perimeter;
                ++perimeter;
            }
        }
    }

    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int distance = abs(graph[y1][x1] - graph[y2][x2]);
        cout << min(distance, perimeter - distance) << endl;
    }

    return 0;
}