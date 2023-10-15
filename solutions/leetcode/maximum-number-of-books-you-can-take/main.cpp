class Solution {
    typedef long long ll;

    struct Pos {
        int i, mx;
        ll total;
    };

   public:
    ll maximumBooks(vector<int>& books) {
        ll result = 0;

        stack<Pos> pos;
        for (int r = 0; r < books.size(); ++r) {
            while (!pos.empty() &&
                   pos.top().mx + (r - pos.top().i) >= books[r]) {
                pos.pop();
            }

            if (pos.empty()) {
                if (r > books[r]) {
                    pos.push({r, books[r], (ll)books[r] * (books[r] + 1) / 2});
                } else {
                    pos.push({r, books[r],
                              (ll)(books[r] + books[r] - r) * (r + 1) / 2});
                }
            } else {
                int d = r - pos.top().i;
                pos.push({r, books[r],
                          pos.top().total +
                              (ll)(books[r] + books[r] - d + 1) * d / 2});
            }

            result = max(result, pos.top().total);
        }

        return result;
    }
};

class Solution {
    struct IndexTotal {
        int i;
        long long total;
    };

   public:
    long long maximumBooks(vector<int>& books) {
        auto calc = [&](int l, int r) -> long long {
            long long d = min(r - l + 1, books[r]);
            return (books[r] * 2 - d + 1) * d / 2;
        };

        long long result = 0;
        stack<IndexTotal> indexTotal;

        for (int i = 0; i < books.size(); ++i) {
            while (!indexTotal.empty() &&
                   books[indexTotal.top().i] + (i - indexTotal.top().i) >=
                       books[i]) {
                indexTotal.pop();
            }

            if (indexTotal.empty()) {
                indexTotal.push({i, calc(0, i)});
            } else {
                indexTotal.push({i, indexTotal.top().total +
                                        calc(indexTotal.top().i + 1, i)});
            }

            cout << indexTotal.top().total << ' ';

            result = max(result, indexTotal.top().total);
        }

        return result;
    }
};
