#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    ll result = 0;
    vector<int> tasks(n);
    for (int i = 0; i < n; ++i) {
        int deadline;
        cin >> tasks[i] >> deadline;
        result += deadline;
    }

    sort(tasks.begin(), tasks.end());

    ll t = 0;
    for (int v : tasks) {
        t += v;
        result -= t;
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
