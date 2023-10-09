#include "bits/stdc++.h"
#define forn(i, b, e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back

// Now you can write sort(all(a))
#define all(a) (a).begin(), (a).end()

// Avoids overflow in "sz(a) - 1" when the size is 0
#define sz(a) ((int)(a).size())

using namespace std;

typedef long long int ll;
typedef long double ldb;
typedef pair<int, int> PII;
typedef vector<int> VI;

inline int readInt() {
    int x;
    cin >> x;
    return x;
}

inline ll readLong() {
    ll x;
    cin >> x;
    return x;
}

inline double readDouble() {
    double x;
    cin >> x;
    return x;
}

inline void solve();

int main() {
    // For testing, it is often more convenient to read from (and write to) a
    // file.
    // freopen("in.txt", "rt", stdin); freopen("out.txt", "wt", stdout);

    // Reasonable initialization of the random engine
    srand((unsigned int)time(0));

    // If you want to use cin/cout instead of scanf/printf, the following line
    // is necessary. Otherwise, it's too slow.
    ios_base::sync_with_stdio(false);
    cout << setprecision(15);

    int t = readInt();
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}

inline void solve() {
    int n = readInt();
    int p = readInt();

    vector<array<int, 2>> residents(n);
    for (int i = 0; i < n; ++i) {
        residents[i][1] = readInt();
    }
    for (int i = 0; i < n; ++i) {
        residents[i][0] = readInt();
    }

    sort(residents.begin(), residents.end());

    vector<ll> costs(n, p);
    for (int l = 0, r = 1; l <= r && r < n; ++l) {
        int c = residents[l][0];
        int m = residents[l][1];
        if (c > p) break;
        while (r < n && m > 0) {
            costs[r++] = c;
            --m;
        }
    }

    cout << accumulate(costs.begin(), costs.end(), 0LL) << '\n';
}
