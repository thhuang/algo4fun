#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    // 0
    // 1
    //
    // 00
    // 10
    // 11
    // 01
    //
    // 000
    // 100
    // 110
    // 010
    // 011
    // 111
    // 101
    // 001

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            int k = 1 << j;
            if (i < k) {
                cout << 0;
            } else {
                (i - k) / k / 2 % 2 == 0 ? cout << 1 : cout << 0;
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
