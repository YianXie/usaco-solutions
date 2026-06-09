#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string cows;
    cin >> n >> cows;

    if (cows.find('1') == string::npos) {
        cout << 0 << endl;
        return 0;
    }

    int days = INT_MAX;
    int consecutive = 0;
    for (int i = 0; i < n; ++i) {
        if (cows[i] == '1') {
            ++consecutive;
        } else {
            days = min(days, (consecutive - 1) / 2);
            consecutive = 0;
        }
    }
    days = min(days, (consecutive - 1) / 2);

    cout << days << endl;

    return 0;
}