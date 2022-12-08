#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    ll n;
    cin >> n;

    ll s = n * (n + 1) / 2;
    if (s & 1) {
        cout << "NO";
        return;
    }

    ll t = s / 2;
    vector<int> v0, v1;

    for (int i = n; i >= 1; --i) {
        if (t >= i) {
            v0.push_back(i);
            t -= i;
        } else {
            v1.push_back(i);
        }
    }

    cout << "YES\n";
    cout << v0.size() << "\n";
    for (int v : v0) cout << v << ' ';
    cout << "\n";
    cout << v1.size() << "\n";
    for (int v : v1) cout << v << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
