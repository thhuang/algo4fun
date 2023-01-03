#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<array<int, 3>> ranges(n);
    for (int i = 0; i < n; ++i) {
        ranges[i][2] = i;
        cin >> ranges[i][0] >> ranges[i][1];
    }

    sort(ranges.begin(), ranges.end(),
         [](array<int, 3>& a, array<int, 3>& b) -> bool {
             if (a[0] != b[0]) return a[0] < b[0];
             return a[1] > b[1];
         });

    vector<bool> inner(n, false), outer(n, false);

    int max_right = 0;
    for (auto [l, r, i] : ranges) {
        if (max_right >= r) inner[i] = true;
        max_right = max(max_right, r);
    }

    int min_right = numeric_limits<int>::max();
    reverse(ranges.begin(), ranges.end());
    for (auto [l, r, i] : ranges) {
        if (min_right <= r) outer[i] = true;
        min_right = min(min_right, r);
    }

    for (bool b : outer) cout << (b ? 1 : 0) << ' ';
    cout << '\n';
    for (bool b : inner) cout << (b ? 1 : 0) << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
