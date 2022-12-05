#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return;
    }
    if (n == 4) {
        cout << "2 4 1 3";
        return;
    }

    for (int i = 1; i <= n; i += 2) cout << i << ' ';
    for (int i = 2; i <= n; i += 2) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
