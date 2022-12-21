#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<int> towers;
    for (int i = 0, v; i < n; ++i) {
        cin >> v;
        auto it = upper_bound(towers.begin(), towers.end(), v);
        if (it == towers.end()) {
            towers.push_back(v);
        } else {
            *it = v;
        }
    }

    cout << towers.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
