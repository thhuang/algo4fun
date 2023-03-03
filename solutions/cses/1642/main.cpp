#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    ll n, x;
    cin >> n >> x;

    vector<array<ll, 2>> nums(n);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        nums[i] = {v, i + 1};
    }

    sort(nums.begin(), nums.end());

    unordered_map<ll, array<ll, 2>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll v = nums[i][0] + nums[j][0];
            int a = nums[i][1];
            int b = nums[j][1];

            if (mp.count(v) > 0) {
                auto [c, d] = mp[v];
                if (a != c && a != d && b != c && b != d) {
                    cout << a << ' ' << b << ' ' << c << ' ' << d;
                    return;
                }
            }

            mp[x - v] = {a, b};
        }
    }

    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
