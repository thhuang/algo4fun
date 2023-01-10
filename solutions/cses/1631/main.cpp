#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    ll sum = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        ll v;
        cin >> v;
        sum += v;
        mx = max(mx, v);
    }

    cout << max(sum, mx << 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
