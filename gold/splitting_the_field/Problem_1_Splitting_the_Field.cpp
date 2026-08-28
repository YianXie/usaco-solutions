#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Cow {
    ll x;
    ll y;
};

struct Record {
    ll minX = LLONG_MAX;
    ll minY = LLONG_MAX;
    ll maxX = LLONG_MIN;
    ll maxY = LLONG_MIN;
};

int n;
ll original;
ll ans;
vector<Cow> cows;

void solve()
{
    sort(cows.begin(), cows.end(), [](Cow a, Cow b) {
        return a.x < b.x;
    });

    vector<Record> pre(n + 1);
    vector<Record> suf(n + 1);
    for (int i = 0; i < n; ++i) {
        Cow& preCow = cows[i];
        Cow& sufCow = cows[n - i - 1];
        pre[i + 1] = { min(pre[i].minX, preCow.x), min(pre[i].minY, preCow.y), max(pre[i].maxX, preCow.x), max(pre[i].maxY, preCow.y) };
        suf[n - i - 1] = { min(suf[n - i].minX, sufCow.x), min(suf[n - i].minY, sufCow.y), max(suf[n - i].maxX, sufCow.x), max(suf[n - i].maxY, sufCow.y) };
    }

    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n && cows[j].x == cows[i].x) {
            j++;
        }
        ll totalArea = (pre[j].maxX - pre[j].minX) * (pre[j].maxY - pre[j].minY) + (suf[j].maxX - suf[j].minX) * (suf[j].maxY - suf[j].minY);
        ans = max(ans, original - totalArea);
        i = j - 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    ll minX = LLONG_MAX;
    ll minY = LLONG_MAX;
    ll maxX = LLONG_MIN;
    ll maxY = LLONG_MIN;

    cin >> n;
    cows.resize(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        cows[i] = { x, y };
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }
    original = (maxX - minX) * (maxY - minY);
    ans = 0;

    solve();
    ll temp;
    for (int i = 0; i < n; ++i) {
        temp = cows[i].x;
        cows[i].x = cows[i].y;
        cows[i].y = temp;
    }
    solve();

    cout << ans << "\n";
    return 0;
}