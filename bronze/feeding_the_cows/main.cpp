#include <bits/stdc++.h>
using namespace std;

int n, k;
string cows;

int solve(char c, vector<char>& ansStr)
{
    int ans = 0, idx = 0;
    while (idx < n) {
        if (cows[idx] == c) {
            int cIdx = min(n - 1, idx + k);
            while (ansStr[cIdx] != '.')
                --cIdx;
            ansStr[cIdx] = c;
            ++ans;
            idx += k * 2 + 1;
        } else {
            ++idx;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k >> cows;

        vector<char> ansStr(n, '.');
        cout << solve('G', ansStr) + solve('H', ansStr) << endl;
        for (const char& c : ansStr)
            cout << c;
        cout << endl;
    }

    return 0;
}