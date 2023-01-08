#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n, t;
    cin >> n >> t;

    vector<int> machines(n);
    for (int i = 0; i < n; ++i) cin >> machines[i];

    ll l = 0;
    ll r = (ll)t * *min_element(machines.begin(), machines.end());

    auto valid = [&](ll v) -> bool {
        ll sum = 0;
        for (int k : machines) sum += v / k;
        return sum >= t;
    };

    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (valid(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
