#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>
using namespace std;

typedef long long ll;

inline void solve() {
    string s;
    cin >> s;

    unordered_map<char, int> charCount;
    int oddCount = 0;

    for (char c : s) {
        if (++charCount[c] & 1) {
            ++oddCount;
        } else {
            --oddCount;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION";
        return;
    }

    string t;
    char oddChar;
    for (auto [c, v] : charCount) {
        t += string(v / 2, c);
        if (v & 1) oddChar = c;
    }

    cout << t;
    if (oddCount) cout << oddChar;
    copy(t.rbegin(), t.rend(), ostream_iterator<char>(cout));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
