#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

inline void solve() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        ull k;
        cin >> k;

        ull offset = 0;
        ull base = 1;
        int d = 1;
        while (k >= offset + base * d * 9) {
            offset += base * d * 9;
            base *= 10;
            ++d;
        }

        ull v = k - offset;
        ull j = v / d;
        ull r = v % d;

        if (r == 0) {
            cout << (base + j - 1) % 10 << "\n";
        } else {
            cout << to_string(base + j)[r - 1] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
