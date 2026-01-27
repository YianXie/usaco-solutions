#include <bits/stdc++.h>
using namespace std;

struct Location {
    bool isTarget;
    int value;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<Location> locations(n);
    for (int i = 0; i < n; ++i)
        cin >> locations[i].isTarget >> locations[i].value;

    set<int> brokenTargets;
    int idx = s - 1, power = 1;
    int lastPad = locations[idx].isTarget ? -1 : idx, direction = 1;
    while (idx >= 0 && idx < n) {
        const Location& current = locations[idx];
        if (current.isTarget && power >= current.value) {
            brokenTargets.insert(idx);
        } else if (!current.isTarget) {
            if (lastPad >= 0 && lastPad != idx && locations[lastPad].value == 0 && current.value == 0)
                break;
            power += current.value;
            direction *= -1;
            lastPad = idx;
        }
        idx += power * direction;
    }

    cout << brokenTargets.size() << endl;
    return 0;
}