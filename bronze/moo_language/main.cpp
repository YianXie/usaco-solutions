#include <bits/stdc++.h>
using namespace std;

char toTypeChar(string type)
{
    if (type == "noun")
        return 'n';
    else if (type == "transitive-verb")
        return 't';
    else if (type == "intransitive-verb")
        return 'i';
    return 'c';
}

bool isValidSentence(vector<char> current)
{
    return current.back() == '.';
}

vector<char> getNextPossible(vector<char>& current)
{
    switch (current.back()) {
    case 'n': {
        // Handle edge case: the initial state
        if (current.size() <= 1)
            return { 'i', 't' };

        // If it is not a full sentence yet
        if (current[current.size() - 2] == '.' || current[current.size() - 2] == 'c')
            return { 'i', 't' };

        int idx = current.size() - 1;
        int periodIdx = -1;
        int conjunctionIdx = -1;
        while (idx-- && (periodIdx == -1 || conjunctionIdx == -1)) {
            if (current[idx] == '.')
                periodIdx = idx;
            else if (current[idx] == 'c')
                conjunctionIdx = idx;
        }

        // If there is no conjunction yet
        if (conjunctionIdx == -1 || periodIdx > conjunctionIdx)
            return { '.', 'c', ',' };

        // If there is already a conjunction
        return { '.', ',' };
    }
    case 't': {
        return { 'n' };
    }
    case 'i': {
        int idx = current.size() - 1;
        int periodIdx = -1;
        int conjunctionIdx = -1;
        while (idx-- && (periodIdx == -1 || conjunctionIdx == -1)) {
            if (current[idx] == '.')
                periodIdx = idx;
            else if (current[idx] == 'c')
                conjunctionIdx = idx;
        }

        // If there is no conjunction yet
        if (conjunctionIdx == -1 || periodIdx > conjunctionIdx)
            return { '.', 'c' };

        // If there is already a conjunction
        return { '.' };
    }
    case 'c': {
        return { 'n' };
    }
    case ',': {
        return { 'n' };
    }
    case '.': {
        return { 'n' };
    }
    }
    return {};
}

vector<char> best = {};
int bestSize = 0;
void getAns(vector<char>& current, unordered_map<char, int>& frequency, vector<char> nextPossible)
{
    if (!current.empty() && isValidSentence(current)) {
        int size = 0;
        for (const char& c : current)
            size += isalpha(static_cast<unsigned char>(c)) != 0;
        if (size > bestSize) {
            best = current;
            bestSize = size;
        }
    }
    for (const char& c : nextPossible) {
        if (frequency[c] <= 0)
            continue;
        current.push_back(c);
        frequency[c]--;

        getAns(current, frequency, getNextPossible(current));

        current.pop_back();
        frequency[c]++;
    }
}

void solve()
{
    int n, c, p;
    cin >> n >> c >> p;
    unordered_map<char, int> frequency;
    unordered_map<char, vector<string>> words;
    frequency[','] = c;
    frequency['.'] = p;

    for (int i = 0; i < n; ++i) {
        string word, type;
        cin >> word >> type;
        frequency[toTypeChar(type)]++;
        words[toTypeChar(type)].push_back(word);
    }

    vector<char> initial = {};
    getAns(initial, frequency, { 'n' });

    string ans = "";
    for (const char& c : best) {
        if (c != '.' && c != ',') {
            ans += ' ';
            ans += words[c].back();
            words[c].pop_back();
        } else {
            ans += c;
        }
    }
    ans.erase(ans.begin(), find_if(ans.begin(), ans.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    ans.erase(find_if(ans.rbegin(), ans.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(),
        ans.end());
    cout << bestSize << "\n";
    cout << ans << "\n";
}

int main()
{
    freopen("inputs/7.in", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        best = {};
        bestSize = 0;
        solve();
    }

    return 0;
}