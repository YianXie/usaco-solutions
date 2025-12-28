#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> moos(n);
    vector<int> distinctions(n);
    distinctions[0] = 1;

    for (int i = 0; i < n; ++i)
        cin >> moos[i];

    set<int> prev = { moos[0] };
    for (int i = 1; i < n; ++i) {
        if (!prev.count(moos[i])) {
            distinctions[i] = distinctions[i - 1] + 1;
            prev.insert(moos[i]);
        } else {
            distinctions[i] = distinctions[i - 1];
        }
    }

    unordered_map<int, int> ans;
    unordered_map<int, bool> found;
    unordered_map<int, bool> recorded;
    unordered_map<int, bool> reduced;
    for (int i = n - 1; i >= 1; --i) {
        int moo = moos[i];
        if (!found[moo]) {
            found[moo] = true;
        } else if (found[moo] && !recorded[moo]) {
            ans[moo] = distinctions[i - 1];
            recorded[moo] = true;
        } else if (found[moo] && recorded[moo] && !reduced[moo]) {
            ans[moo] -= 1;
            reduced[moo] = true;
        }
    }

    long long total = 0;
    for (const auto& pair : ans)
        total += pair.second;

    cout << total << endl;
    return 0;
}