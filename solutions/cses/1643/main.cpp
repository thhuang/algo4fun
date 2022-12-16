#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    ll result = *max_element(nums.begin(), nums.end());
    ll curr = 0;
    for (int v : nums) {
        curr += v;
        if (curr < 0) {
            curr = 0;
            continue;
        }
        result = max(result, curr);
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
