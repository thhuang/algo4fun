#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

inline void solve() {
    int n, k;
    cin >> n >> k;

    ordered_set<int> nums;
    for (int i = 1; i <= n; ++i) nums.insert(i);

    int i = 0;
    while (nums.size() > 0) {
        i = (i + k) % nums.size();
        auto it = nums.find_by_order(i);
        cout << *it << ' ';
        nums.erase(it);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
