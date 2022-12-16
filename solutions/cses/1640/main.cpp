#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n, x;
    cin >> n >> x;

    unordered_map<ll, int> mp;
    for (int i = 1; i <= n; ++i) {
        ll v;
        cin >> v;
        if (mp.count(v)) {
            cout << mp[v] << ' ' << i;
            return;
        }
        mp[x - v] = i;
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
