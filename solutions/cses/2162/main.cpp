#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);

    int init = 1;
    int i = init;
    unordered_set<int> vis;
    while (nums.size() > 0) {
        i %= nums.size();
        for (; i < nums.size(); i += 2) {
            cout << nums[i] << ' ';
            vis.insert(nums[i]);
        }
        vector<int> newNums;
        copy_if(nums.begin(), nums.end(), back_inserter(newNums),
                [&](int v) { return vis.count(v) == 0; });
        i -= nums.size();
        nums = move(newNums);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
