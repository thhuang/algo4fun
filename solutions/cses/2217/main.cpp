#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n + 1);
    vector<int> indices(n + 2);
    indices.front() = numeric_limits<int>::max();
    indices.back() = numeric_limits<int>::min();

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        indices[nums[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int v = nums[i];
        if (indices[v - 1] > indices[v]) ++cnt;
    }

    for (int q = 0; q < m; ++q) {
        int i, j;
        cin >> i >> j;

        if (i > j) swap(i, j);

        int a = nums[i];
        int b = nums[j];

        if (a + 1 == b) --cnt;
        if (a - 1 == b) ++cnt;

        if (indices[a - 1] < indices[a]) ++cnt;
        if (indices[a] < indices[a + 1]) ++cnt;
        if (indices[b - 1] < indices[b]) ++cnt;
        if (indices[b] < indices[b + 1]) ++cnt;

        swap(nums[i], nums[j]);
        swap(indices[a], indices[b]);

        if (indices[a - 1] < indices[a]) --cnt;
        if (indices[a] < indices[a + 1]) --cnt;
        if (indices[b - 1] < indices[b]) --cnt;
        if (indices[b] < indices[b + 1]) --cnt;

        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
