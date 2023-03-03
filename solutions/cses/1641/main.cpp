#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline void solve() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        nums[i] = {v, i + 1};
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        int l = i + 1;
        int r = n - 1;
        while (l < r) {
            int v = nums[i].first + nums[l].first + nums[r].first;
            if (v == x) {
                cout << nums[i].second << ' ' << nums[l].second << ' ' << nums[r].second;
                return;
            }
            v < x ? ++l : --r;
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
