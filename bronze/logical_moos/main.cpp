#include <bits/stdc++.h>
using namespace std;

struct Pos {
    int firstTrue, lastTrue, firstFalse, lastFalse;
};

bool evaluate(vector<string> statements)
{
    for (const string& str : statements)
        if (str == "false")
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<string>> segments = { {} };
    vector<int> segmentPosition(n, -1);
    vector<bool> evaluated;
    vector<Pos> position;
    int firstEvaluatedTrue = -1, lastEvaluatedTrue = -1;

    int firstTrue = -1, lastTrue = -1, firstFalse = -1, lastFalse = -1;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (str != "or") {
            segments.back().push_back(str);
            segmentPosition[i] = segments.size() - 1;
        }

        if (str == "false") {
            if (firstFalse == -1)
                firstFalse = i;
            lastFalse = i;
        } else if (str == "true") {
            if (firstTrue == -1)
                firstTrue = i;
            lastTrue = i;
        }

        if (str == "or" || i == n - 1) {
            // Evaluate the expression
            const bool result = evaluate(segments.back());
            if (result) {
                if (firstEvaluatedTrue == -1)
                    firstEvaluatedTrue = segments.size() - 1;
                lastEvaluatedTrue = segments.size() - 1;
            }
            evaluated.push_back(result);

            // Add the position and reset the temp pos
            Pos pos;
            pos.firstTrue = firstTrue;
            pos.lastTrue = lastTrue;
            pos.firstFalse = firstFalse;
            pos.lastFalse = lastFalse;
            position.push_back(pos);
            firstTrue = -1;
            lastTrue = -1;
            firstFalse = -1;
            lastFalse = -1;

            // Add a new segment
            if (i < n - 1)
                segments.push_back({});

            continue;
        }
    }

    string ans = "";
    for (int i = 0; i < q; ++i) {
        int left, right;
        string target;
        cin >> left >> right >> target;

        if (target == "false") {
            if (firstEvaluatedTrue == -1) {
                ans += 'Y';
                continue;
            }

            if (left - 1 <= position[firstEvaluatedTrue].lastTrue && right - 1 >= position[lastEvaluatedTrue].firstTrue) {
                ans += 'Y';
            } else {
                ans += 'N';
            }
        } else {
            if ((firstEvaluatedTrue != -1 && position[firstEvaluatedTrue].lastTrue < left - 1) || (lastEvaluatedTrue != -1 && position[lastEvaluatedTrue].firstTrue > right - 1)) {
                ans += 'Y';
                continue;
            }

            const int& leftPos = segmentPosition[left - 1];
            const int& rightPos = segmentPosition[right - 1];
            if ((left - 1 <= position[leftPos].firstFalse || position[leftPos].firstFalse == -1) && (right - 1 >= position[rightPos].lastFalse || position[rightPos].lastFalse == -1)) {
                ans += 'Y';
            } else {
                ans += 'N';
            }
        }
    }

    cout << ans << endl;
    return 0;
}