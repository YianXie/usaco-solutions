#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> cntXY(n, vector<int>(n));
    vector<vector<int>> cntXZ(n, vector<int>(n));
    vector<vector<int>> cntYZ(n, vector<int>(n));

    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        ans += ++cntXY[x][y] == n;
        ans += ++cntXZ[x][z] == n;
        ans += ++cntYZ[y][z] == n;
        cout << ans << endl;
    }

    return 0;
}