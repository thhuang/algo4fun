#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    for (ll k = 1, v = 0; k <= n; ++k) {
        v += (k * 2 - 1) * (k - 1) * (k - 1);
        v += (k * 2 - 1) * (k * 2 - 2) / 2;

        if (k >= 3) v -= 4;
        v -= (max(0LL, k - 3) + max(0LL, k - 2)) * 4;

        cout << v << "\n";
    }
}

inline void solve1() {
    int n;
    cin >> n;

    for (ll i = 1; i <= n; ++i) {
        cout << i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve1();

    return 0;
}
