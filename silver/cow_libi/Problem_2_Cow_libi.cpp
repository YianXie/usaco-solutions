#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Grazing {
    ll x, y, t;
};

bool grazingCmp(Grazing a, Grazing b)
{
    return a.t < b.t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int g, n;
    cin >> g >> n;

    vector<Grazing> grazings(g);
    for (int i = 0; i < g; ++i) {
        ll x, y, t;
        cin >> x >> y >> t;
        grazings[i] = { x, y, t };
    }
    sort(grazings.begin(), grazings.end(), grazingCmp);

    int ans = n;
    for (int i = 0; i < n; ++i) {
        ll x, y, t;
        cin >> x >> y >> t;
        Grazing grazing;
        grazing.t = t;
        int right = upper_bound(grazings.begin(), grazings.end(), grazing, grazingCmp) - grazings.begin();
        int left = right - 1;

        if (right < g) {
            Grazing& rightGrazing = grazings[right];
            ll distance = (rightGrazing.x - x) * (rightGrazing.x - x) + (rightGrazing.y - y) * (rightGrazing.y - y);
            if (distance > ((rightGrazing.t - t) * (rightGrazing.t - t))) {
                continue;
            }
        }
        if (left >= 0) {
            Grazing& leftGrazing = grazings[left];
            ll distance = (leftGrazing.x - x) * (leftGrazing.x - x) + (leftGrazing.y - y) * (leftGrazing.y - y);
            if (distance > ((leftGrazing.t - t) * (leftGrazing.t - t))) {
                continue;
            }
        }
        ans--;
    }

    cout << ans << "\n";
    return 0;
}