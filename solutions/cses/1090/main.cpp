#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    sort(p.begin(), p.end());

    int result = 0;
    for (int l = 0, r = n - 1; l <= r;) {
        if (x - p[r--] >= p[l]) ++l;
        ++result;
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
