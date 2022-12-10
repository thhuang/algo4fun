#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);
        int diff = b - a;
        a -= diff;

        if (a >= 0 && a % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
