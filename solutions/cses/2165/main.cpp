#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> steps;
    function<void(int, int, int, int)> f = [&](int from, int to, int mid,
                                               int i) -> void {
        if (i == 1) {
            steps.push_back({from, to});
            return;
        }
        f(from, mid, to, i - 1);
        f(from, to, mid, 1);
        f(mid, to, from, i - 1);
    };

    f(1, 3, 2, n);

    cout << steps.size() << "\n";
    for (auto [from, to] : steps) cout << from << ' ' << to << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
