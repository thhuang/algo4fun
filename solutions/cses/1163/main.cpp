#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int x, n;
    cin >> x >> n;

    set<int> lights = {0, x};
    map<int, int> dists = {{x, 1}};

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        auto it = lights.upper_bound(v);
        int r = *it;
        int l = *prev(it);

        if (int d = r - l; --dists[d] == 0) dists.erase(d);

        lights.insert(v);
        ++dists[r - v];
        ++dists[v - l];

        cout << dists.rbegin()->first << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
