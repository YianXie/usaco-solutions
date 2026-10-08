#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int seniority, a, t;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n;
    cin >> n;

    vector<Cow> cows(n);
    for (int i = 0; i < n; ++i) {
        int a, t;
        cin >> a >> t;
        cows[i] = { i, a, t };
    }
    sort(cows.begin(), cows.end(), [](const Cow& a, const Cow& b) {
        if (a.a != b.a) {
            return a.a < b.a;
        }
        return a.seniority < b.seniority;
    });

    auto comp = [](const Cow& a, const Cow& b) {
        return a.seniority > b.seniority;
    };
    priority_queue<Cow, vector<Cow>, decltype(comp)> pq(comp);

    int next = 0;
    int ans = 0;
    int time = 0;
    while (next < n || !pq.empty()) {
        if (pq.empty() && time < cows[next].a) {
            time = cows[next].a;
        }
        while (next < n && cows[next].a <= time) {
            pq.push(cows[next++]);
        }
        Cow curr = pq.top();
        pq.pop();
        ans = max(ans, time - curr.a);
        time += curr.t;
    }

    cout << ans << "\n";
    return 0;
}