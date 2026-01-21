#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int numOne = 0;
    vector<int> numbers(n - 1);
    vector<int> frequency(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> numbers[i];
        numOne += numbers[i] == 1;
        ++frequency[numbers[i] - 1];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (numbers[i] > n || numbers[i] <= 0) {
            cout << -1 << endl;
            return;
        }
        if (frequency[numbers[i] - 1] > 1 && numbers[i] != 1) {
            cout << -1 << endl;
            return;
        }
    }

    if (numOne <= 0 || numOne > 2 || numbers.back() != 1) {
        cout << -1 << endl;
        return;
    }

    vector<int> notFound;
    for (int i = 0; i < n; ++i)
        if (!frequency[i])
            notFound.push_back(i + 1);

    vector<int> ans(n);
    if (numOne == 1) {
        for (int i = n - 2; i >= 0; --i) {
            ans[n - i - 2] = numbers[i];
        }
        ans.back() = notFound[0];
    } else {
        ans[0] = min(notFound[0], notFound[1]);
        ans.back() = max(notFound[0], notFound[1]);

        int front = 0, back = n - 1;
        int length = 2;
        while (length < n) {
            int val = numbers[length - 2];
            if (ans[front] > ans[back]) {
                ans[front + 1] = val;
                ++front;
            } else {
                ans[back - 1] = val;
                --back;
            }
            ++length;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;
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