#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

typedef long long ll;

inline void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> result;
    do {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << result.size() << "\n";
    for (string t : result) cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
