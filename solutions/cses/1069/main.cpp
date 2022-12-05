#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int result = 0;
    for (int l = 0; l < n;) {
        int r = l + 1;
        while (r < n && s[r] == s[l]) ++r;
        result = max(result, r - l);
        l = r;
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
