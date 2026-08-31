#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Store {
    ll amount, price;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;

    vector<ll> cows(n);
    vector<Store> stores(m);
    vector<ll> rentals(r);

    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    for (int i = 0; i < m; ++i) {
        ll amount, price;
        cin >> amount >> price;
        stores[i] = { amount, price };
    }
    for (int i = 0; i < r; ++i) {
        cin >> rentals[i];
    }

    sort(cows.begin(), cows.end(), [](ll a, ll b) {
        return a > b;
    });
    sort(stores.begin(), stores.end(), [](Store a, Store b) {
        return a.price > b.price;
    });
    sort(rentals.begin(), rentals.end(), [](ll a, ll b) {
        return a > b;
    });

    vector<ll> storesPre(n + 1);
    vector<ll> rentalsPre(n + 1);

    int nextStoreIdx = 0;
    int numCows = 1;
    bool sameCow = false;
    while (numCows <= n) {
        if (nextStoreIdx >= m) {
            if (!sameCow)
                storesPre[numCows] = storesPre[numCows - 1];
        } else {
            Store& store = stores[nextStoreIdx];
            ll profit = store.price * min(store.amount, cows[numCows - 1]);
            if (sameCow) {
                storesPre[numCows] += profit;
            } else {
                storesPre[numCows] = storesPre[numCows - 1] + profit;
            }

            if (cows[numCows - 1] > store.amount) {
                nextStoreIdx++;
                cows[numCows - 1] -= store.amount;
                sameCow = true;
                continue;
            } else if (cows[numCows - 1] == store.amount) {
                nextStoreIdx++;
            } else {
                store.amount -= cows[numCows - 1];
            }
        }
        sameCow = false;
        numCows++;
    }
    numCows = 1;
    while (numCows <= n) {
        if (numCows > r) {
            rentalsPre[numCows] = rentalsPre[numCows - 1];
        } else {
            rentalsPre[numCows] = rentalsPre[numCows - 1] + rentals[numCows - 1];
        }
        numCows++;
    }

    ll bestProfit = 0;
    for (int i = 0; i <= n; ++i) {
        ll profit = storesPre[n - i] + rentalsPre[i];
        bestProfit = max(bestProfit, profit);
    }

    cout << bestProfit << "\n";
    return 0;
}