#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 48;
array<pair<int, int>, 4> directions = {
    pair<int, int>{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
array<int, n> path;
array<array<bool, 9>, 9> grid;

inline int search(int k, int i, int j) {
    if (grid[i][j - 1] && grid[i][j + 1] && !grid[i - 1][j] && !grid[i + 1][j])
        return 0;
    if (grid[i - 1][j] && grid[i + 1][j] && !grid[i][j - 1] && !grid[i][j + 1])
        return 0;

    if (i == 7 && j == 1) {
        if (k == n) return 1;
        return 0;
    }

    int result = 0;
    grid[i][j] = true;

    if (path[k] < 4) {
        auto [di, dj] = directions[path[k]];
        if (!grid[i + di][j + dj]) result += search(k + 1, i + di, j + dj);
    } else {
        for (int dir = 0; dir < 4; ++dir) {
            auto [di, dj] = directions[dir];
            if (!grid[i + di][j + dj]) result += search(k + 1, i + di, j + dj);
        }
    }

    grid[i][j] = false;
    return result;
};

inline void solve() {
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'D') {
            path[i] = 0;
        } else if (c == 'U') {
            path[i] = 1;
        } else if (c == 'L') {
            path[i] = 2;
        } else if (c == 'R') {
            path[i] = 3;
        } else {  // c == '?'
            path[i] = 4;
        }
    }

    for (int i = 0; i < 9; ++i) {
        grid[i][0] = grid[i][8] = grid[0][i] = grid[8][i] = true;
    }

    cout << search(0, 1, 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
