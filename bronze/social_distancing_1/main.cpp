#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    int n;
    string stalls;
    cin >> n >> stalls;

    if (stalls.find('1') == string::npos) {
        cout << n - 1 << endl;
        return 0;
    }

    vector<int> weights;
    int closest = n;
    int last = -1;
    for (int i = 0; i < n; ++i) {
        if (stalls[i] == '0' && last == -1) {
            last = i;
        } else if (stalls[i] != '0' && last != -1) {
            int diff = i - last;
            if (last != 0)
                closest = min(closest, diff);
            if (last == 0)
                diff = diff * 2 - 1;
            weights.push_back(diff);
            last = -1;
        }
    }
    if (last != -1)
        weights.push_back((n - last) * 2 - 1);

    if (weights.size() == 1) {
        if (stalls.front() == '0' || stalls.back() == '0')
            cout << (weights[0] / 2 + 2) / 2 << endl;
        else
            cout << (weights[0] + 3 - 1) / 3 << endl;
        return 0;
    }
    sort(weights.begin(), weights.end(), greater<int>());
    cout << min(closest + 1, (weights[1] + 2 - 1) / 2) << endl;

    return 0;
}