#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    unordered_set<int> rounds;
    for (int i = 0, v; i < n; ++i) {
        cin >> v;
        if (auto it = rounds.find(v - 1); it != rounds.end()) rounds.erase(it);
        rounds.insert(v);
    }

    cout << rounds.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
