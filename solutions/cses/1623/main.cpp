#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    ll sum = 0;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        nums.push_back(v);
        sum += v;
    }

    ll result = sum;
    ll curr = 0;
    function<void(int)> dfs = [&](int i) -> void {
        ll diff = sum - curr - curr;
        result = min(result, abs(diff));
        if (i == n || diff < 0) return;

        dfs(i + 1);
        curr += nums[i];
        dfs(i + 1);
        curr -= nums[i];
    };

    dfs(0);

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
