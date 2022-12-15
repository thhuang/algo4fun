#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        t.push_back({a, 1});
        t.push_back({b, -1});
    }

    sort(t.begin(), t.end());

    int result = 0;
    int curr = 0;
    for (auto [_, diff] : t) {
        result = max(result, curr += diff);
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
