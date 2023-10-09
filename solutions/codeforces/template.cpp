// Warning: this file uses some very, very bad code style. Don't do this in real
// life.

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

    solve();

    return 0;
}

inline void solve() {}
