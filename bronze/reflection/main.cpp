#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u;
    cin >> n >> u;

    vector<vector<int>> img(n, vector<int>(n));
    vector<vector<int>> partial(n / 2, vector<int>(n / 2));
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j)
            img[i][j] = row[j] == '#' ? 1 : 0;
    }

    int sum = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int count = 0;
            int cell = img[i][j];
            if (img[i][n - j - 1] == cell)
                count++;
            if (img[n - i - 1][j] == cell)
                count++;
            if (img[n - i - 1][n - j - 1] == cell)
                count++;

            if (count == 0) {
                sum += 1;
                partial[i][j] = 1;
            } else {
                sum += 3 - count;
                partial[i][j] = 3 - count;
            }
        }
    }
    cout << sum << endl;

    for (int i = 0; i < u; i++) {
        int x, y;
        cin >> x >> y;
        img[x - 1][y - 1] = img[x - 1][y - 1] == 1 ? 0 : 1;

        int count = 0;
        int cell = img[x - 1][y - 1];
        if (img[x - 1][n - y] == cell)
            count++;
        if (img[n - x][y - 1] == cell)
            count++;
        if (img[n - x][n - y] == cell)
            count++;

        int tempX = x - 1;
        int tempY = y - 1;
        if (x > n / 2) {
            tempX = -x + n;
        }
        if (y > n / 2) {
            tempY = -y + n;
        }
        if (count == 0) {
            sum += 1 - partial[tempX][tempY];
            partial[tempX][tempY] = 1;
        } else {
            sum += (3 - count) - partial[tempX][tempY];
            partial[tempX][tempY] = 3 - count;
        }
        cout << sum << endl;
    }

    return 0;
}