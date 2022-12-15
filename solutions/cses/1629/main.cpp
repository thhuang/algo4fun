#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> mov(n);
    for (int i = 0; i < n; ++i) cin >> mov[i][1] >> mov[i][0];

    sort(mov.begin(), mov.end());

    int result = 0;
    for (int i = 0, t = numeric_limits<int>::min(); i < n; ++i) {
        if (mov[i][1] >= t) {
            t = mov[i][0];
            ++result;
        }
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
