#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<array<int, 3>> customers(n);
    for (int i = 0; i < n; ++i) {
        customers[i][2] = i;
        cin >> customers[i][0] >> customers[i][1];
    }

    sort(customers.begin(), customers.end());

    vector<int> rooms;
    vector<int> result(n);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    for (auto [l, r, i] : customers) {
        while (!pq.empty() && pq.top()[0] < l) {
            rooms.push_back(pq.top()[1]);
            pq.pop();
        }

        if (rooms.empty()) rooms.push_back(pq.size() + 1);

        int v = rooms.back();
        rooms.pop_back();

        pq.push({r, v});

        result[i] = v;
    }

    cout << *max_element(result.begin(), result.end()) << '\n';
    for (int v : result) cout << v << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
