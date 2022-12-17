#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    sort(nums.begin(), nums.end(), greater<>());

    ll sum = 0;
    while (!nums.empty() && nums.back() <= sum + 1) {
        sum += nums.back();
        nums.pop_back();
    }

    cout << sum + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
