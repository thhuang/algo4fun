#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    int result = n;
    for (int i = 1, v; i < n; ++i) {
        cin >> v;
        result = result ^ v ^ i;
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
