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

inline void solve1() {
    int x, n;
    cin >> x >> n;

    vector<int> lights = {0, x};
    set<int> passage = {0, x};
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        lights.push_back(v);
        passage.insert(v);
    }

    reverse(lights.begin(), lights.end());

    int mx = 0;
    for (auto it = passage.begin(); it != prev(passage.end()); ++it) {
        mx = max(mx, *next(it) - *it);
    }

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = mx;
        auto it = passage.find(lights[i]);
        mx = max(mx, *next(it) - *prev(it));
        passage.erase(it);
    }

    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        cout << *it << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve1();

    return 0;
}
