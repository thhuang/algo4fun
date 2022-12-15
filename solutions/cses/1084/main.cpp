#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> want(n), got(m);
    for (int i = 0; i < n; ++i) cin >> want[i];
    for (int i = 0; i < m; ++i) cin >> got[i];

    sort(want.begin(), want.end(), greater<>());
    sort(got.begin(), got.end(), greater<>());

    int result = 0;
    while (!want.empty() && !got.empty()) {
        if (want.back() < got.back()) {
            if (got.back() - k <= want.back()) {
                ++result;
                got.pop_back();
            }
            want.pop_back();
        } else {  // want.back() >= got.back()
            if (want.back() - k <= got.back()) {
                ++result;
                want.pop_back();
            }
            got.pop_back();
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
