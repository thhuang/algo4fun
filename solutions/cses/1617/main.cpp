#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

inline void solve() {
    int n;
    cin >> n;

    ll result = 1;
    for (int i = 0; i < n; ++i) {
        result <<= 1;
        result %= mod;
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
