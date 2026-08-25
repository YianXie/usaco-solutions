#include <bits/stdc++.h>
using namespace std;

struct Lifeguard {
    int start;
    int end;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;

    vector<Lifeguard> lifeguards(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        lifeguards[i] = { start, end };
    }
    sort(lifeguards.begin(), lifeguards.end(), [](Lifeguard a, Lifeguard b) {
        return a.start < b.start;
    });

    vector<int> maxEnd(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        maxEnd[i + 1] = max(maxEnd[i], lifeguards[i].end);
    }

    int totalTime = lifeguards[0].end - lifeguards[0].start;
    for (int i = 1; i < n; ++i) {
        int gain = max(0, lifeguards[i].end - max(lifeguards[i].start, maxEnd[i]));
        totalTime += gain;
    }

    vector<int> individuals(n);
    individuals[0] = min(lifeguards[0].end, lifeguards[1].start) - lifeguards[0].start;
    for (int i = 1; i < n - 1; ++i) {
        individuals[i] = max(0, min(lifeguards[i].end, lifeguards[i + 1].start) - max(lifeguards[i].start, maxEnd[i]));
    }
    individuals[n - 1] = max(0, lifeguards[n - 1].end - max(lifeguards[n - 1].start, maxEnd[n - 1]));

    int smallest = INT_MAX;
    for (const int& i : individuals) {
        smallest = min(smallest, i);
    }

    cout << totalTime - smallest << "\n";
    return 0;
}