#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x;
    int y;
    bool faceEast;
};

struct StopEvent {
    int victimTime;
    int eaterTime;
    int eater;
    int victim;
};

int n;
vector<Cow> cows;
vector<StopEvent> stops;
vector<int> stoppedRound;
vector<int> stoppedBy;
vector<int> ans;

void computeAns(int idx)
{
    if (stoppedBy[idx] == -1) {
        return;
    }
    ans[stoppedBy[idx]]++;
    computeAns(stoppedBy[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cows.resize(n);
    stoppedRound.resize(n);
    fill(stoppedRound.begin(), stoppedRound.end(), -1);
    stoppedBy.resize(n);
    fill(stoppedBy.begin(), stoppedBy.end(), -1);
    ans.resize(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        char direction;
        cin >> direction >> x >> y;
        cows[i] = { x, y, direction == 'E' };
    }

    for (int i = 0; i < n; ++i) {
        if (!cows[i].faceEast) {
            continue;
        }

        Cow& eastCow = cows[i];
        for (int j = 0; j < n; ++j) {
            if (cows[j].faceEast || cows[j].x < cows[i].x || cows[j].y > cows[i].y) {
                continue;
            }

            Cow& northCow = cows[j];
            int distance = (northCow.x - eastCow.x) - (eastCow.y - northCow.y);
            if (distance > 0) {
                // the east cow will be eaten
                stops.push_back({ northCow.x - eastCow.x, eastCow.y - northCow.y, j, i });
            } else if (distance < 0) {
                // the north cow will be eaten
                stops.push_back({ eastCow.y - northCow.y, northCow.x - eastCow.x, i, j });
            }
        }
    }
    sort(stops.begin(), stops.end(), [](StopEvent a, StopEvent b) {
        return a.victimTime < b.victimTime;
    });

    for (int i = 0; i < stops.size(); ++i) {
        StopEvent& stop = stops[i];
        if (stoppedRound[stop.victim] == -1 && (stoppedRound[stop.eater] == -1 || stoppedRound[stop.eater] >= stop.eaterTime)) {
            // if the victim is not stopped yet and the eater did not stop before the interaction time, commit it
            stoppedRound[stop.victim] = stop.victimTime;
            stoppedBy[stop.victim] = stop.eater;
        }
    }

    for (int i = 0; i < n; ++i) {
        computeAns(i);
    }
    for (const int& i : ans) {
        cout << i << "\n";
    }

    return 0;
}