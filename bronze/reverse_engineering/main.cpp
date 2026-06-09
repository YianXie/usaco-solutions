#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> keys(m);
    vector<int> values(m);

    for (int i = 0; i < m; ++i)
        cin >> keys[i] >> values[i];

    int erased = 0;
    while (true) {
        bool madeProgress = false, foundAns = false;
        for (int i = 0; i < n; ++i) {
            if (keys.empty()) {
                foundAns = true;
                break;
            }

            int firstZeroValue = -1, firstOneValue = -1;
            bool zeroOk = true, oneOk = true;

            for (int j = 0; j < keys.size(); ++j) {
                if (keys[j][i] == '0' && zeroOk) {
                    if (firstZeroValue == -1)
                        firstZeroValue = values[j];
                    else if (values[j] != firstZeroValue)
                        zeroOk = false;
                } else if (keys[j][i] == '1' && oneOk) {
                    if (firstOneValue == -1)
                        firstOneValue = values[j];
                    else if (values[j] != firstOneValue)
                        oneOk = false;
                }
            }

            int idx = 0;
            while (idx < keys.size()) {
                if ((zeroOk && keys[idx][i] == '0') || (oneOk && keys[idx][i] == '1')) {
                    keys.erase(keys.begin() + idx);
                    values.erase(values.begin() + idx);
                    --idx;
                }
                ++idx;
            }
            if (!madeProgress)
                madeProgress = (zeroOk && firstZeroValue != -1) || (oneOk && firstOneValue != -1);
        }

        if (foundAns) {
            cout << "OK" << endl;
            break;
        } else if (!madeProgress) {
            cout << "LIE" << endl;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}