#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int t;
    cin >> t;

    while (t--) {
        ll i, j;
        cin >> i >> j;

        ll mx = max(i, j);
        if (i == mx) {
            if (mx & 1) {
                --mx;
                cout << mx * mx + j;
            } else {
                cout << mx * mx - j + 1;
            }
        } else {  // j == mx
            if (mx & 1) {
                cout << mx * mx - i + 1;
            } else {
                --mx;
                cout << mx * mx + i;
            }
        }

        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
