#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        nums.push_back(v);
    }

    ll result = 0;
    int mx = nums.front();
    for (int v : nums) {
        result += max(0, mx - v);
        mx = max(mx, v);
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
