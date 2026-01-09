#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string breed;
    cin >> n >> breed;

    unordered_map<char, pair<int, int>> occurrence = {
        { 'G', { n, 0 } },
        { 'H', { n, 0 } }
    };
    for (int i = 0; i < n; ++i) {
        if (breed[i] == 'G') {
            occurrence['G'].first = min(occurrence['G'].first, i);
            occurrence['G'].second = i;
        } else if (breed[i] == 'H') {
            occurrence['H'].first = min(occurrence['H'].first, i);
            occurrence['H'].second = i;
        }
    }

    vector<int> list(n);
    for (int i = 0; i < n; ++i)
        cin >> list[i];

    int ans = 0;
    bool countedRoot = false;

    // Check for G if G contains all of its breed
    if (list[occurrence['G'].first] - 1 >= occurrence['G'].second) {
        for (int i = 0; i < occurrence['G'].first; ++i) {
            if (breed[i] == 'G')
                continue;
            if (list[i] - 1 >= occurrence['G'].first) {
                ++ans;
                if (i == occurrence['H'].first)
                    countedRoot = true;
            }
        }
    }

    // Check for H
    if (list[occurrence['H'].first] - 1 >= occurrence['H'].second) {
        for (int i = 0; i < occurrence['H'].first; ++i) {
            if (breed[i] == 'H')
                continue;
            if (list[i] - 1 >= occurrence['H'].first) {
                ++ans;
                if (i == occurrence['G'].first)
                    countedRoot = true;
            }
        }
    }

    if (!countedRoot && list[occurrence['G'].first] - 1 >= occurrence['G'].second && list[occurrence['H'].first] - 1 >= occurrence['H'].second)
        ++ans;

    cout << ans << endl;
    return 0;
}