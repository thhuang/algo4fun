#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    int result = 0;
    unordered_set<int> seen;
    for (int l = 0, r = 0; r < n; ++r) {
        while (seen.count(nums[r]) > 0) seen.erase(nums[l++]);
        seen.insert(nums[r]);
        result = max(result, r - l + 1);
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
