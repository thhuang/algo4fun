#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    ll n;
    cin >> n;

    while (true) {
        cout << n << ' ';
        if (n == 1) break;
        if (n & 1) {
            n = n * 3 + 1;
        } else {
            n >>= 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
