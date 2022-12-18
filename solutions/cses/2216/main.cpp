#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    unordered_set<int> rounds;
    for (int i = 0, v; i < n; ++i) {
        cin >> v;
        if (auto it = rounds.find(v - 1); it != rounds.end()) rounds.erase(it);
        rounds.insert(v);
    }

    cout << rounds.size();
}

inline void solve1() {
    int n;
    cin >> n;

    vector<int> nums(n + 1);
    vector<int> indices(n + 1, n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        indices[nums[i]] = i;
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int v = nums[i];
        if (indices[v - 1] > indices[v]) ++cnt;
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
