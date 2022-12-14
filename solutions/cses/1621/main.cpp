#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    unordered_set<int> nums;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        nums.insert(v);
    }

    cout << nums.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
