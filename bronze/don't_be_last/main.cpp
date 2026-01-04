#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    int n;
    cin >> n;

    map<string, int> logs = {
        { "Bessie", 0 }, { "Elsie", 0 }, { "Daisy", 0 }, { "Gertie", 0 }, { "Annabelle", 0 }, { "Maggie", 0 }, { "Henrietta", 0 }
    };
    for (int i = 0; i < n; ++i) {
        string name;
        int amount;
        cin >> name >> amount;
        logs[name] += amount;
    }

    vector<pair<string, int>> list(logs.begin(), logs.end());
    sort(list.begin(), list.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    });

    for (int i = 1; i < 7; ++i) {
        const auto& current = list[i];
        if (current.second != list[i - 1].second) {
            if ((i == 6) || (i + 1 < 7 && current.second != list[i + 1].second)) {
                cout << current.first << endl;
            } else {
                cout << "Tie" << endl;
            }
            return 0;
        }
    }

    cout << "Tie" << endl;
    return 0;
}