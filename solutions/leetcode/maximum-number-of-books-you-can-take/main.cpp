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
