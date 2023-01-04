#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

// https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/
// https://codeforces.com/blog/entry/11080
// https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<array<int, 3>> ranges(n);
    for (int i = 0; i < n; ++i) {
        ranges[i][2] = i;
        cin >> ranges[i][0] >> ranges[i][1];
    }

    sort(ranges.begin(), ranges.end(),
         [](array<int, 3>& a, array<int, 3>& b) -> bool {
             if (a[0] != b[0]) return a[0] < b[0];
             return a[1] > b[1];
         });

    vector<int> inner(n, 0), outer(n, 0);
    ordered_set<array<int, 2>> right_order;

    for (auto [l, r, i] : ranges) {
        right_order.insert({r, -l});
        inner[i] = right_order.size() - right_order.order_of_key({r, -l}) - 1;
    }

    right_order.clear();
    reverse(ranges.begin(), ranges.end());
    for (auto [l, r, i] : ranges) {
        right_order.insert({r, -l});
        outer[i] = right_order.order_of_key({r, -l});
    }

    for (int v : outer) cout << v << ' ';
    cout << '\n';
    for (int v : inner) cout << v << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
