#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n;
    cin >> n;

    vector<map<char, int>> pre(n + 1, {{'H', 0}, {'P', 0}, {'S', 0}});
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        pre[i + 1] = pre[i];
        pre[i + 1][c]++;
    }

    int best = 0;
    auto &last = pre.back();

    for (int i = 1; i <= n; ++i)
    {
        auto currentPair = pre[i];
        int before = max({currentPair['H'], currentPair['P'], currentPair['S']});
        best = max({best, before + last['H'] - currentPair['H'], before + last['P'] - currentPair['P'], before + last['S'] - currentPair['S']});
    }

    cout << best << endl;
    return 0;
}