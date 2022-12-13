#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) cin >> board[i];

    int result = 0;
    vector<bool> col(8), diag0(15), diag1(15);

    function<void(int)> dfs = [&](int i) -> void {
        if (i == 8) {
            ++result;
            return;
        }
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == '*') continue;
            if (col[j] || diag0[i + j] || diag1[i - j + 7]) continue;
            col[j] = diag0[i + j] = diag1[i - j + 7] = true;
            dfs(i + 1);
            col[j] = diag0[i + j] = diag1[i - j + 7] = false;
        }
    };

    dfs(0);

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
