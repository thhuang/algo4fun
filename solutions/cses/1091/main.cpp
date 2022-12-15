#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> h;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        h.insert(v);
    }

    vector<int> result;
    for (int i = 0, t; i < m; ++i) {
        cin >> t;
        auto it = h.upper_bound(t);
        if (it == h.begin()) {
            result.push_back(-1);
        } else {
            --it;
            result.push_back(*it);
            h.erase(it);
        }
    }

    for (int v : result) cout << v << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
