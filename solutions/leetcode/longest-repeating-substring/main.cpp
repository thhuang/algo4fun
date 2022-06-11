class Solution {
    struct Node {
        array<Node*, 26> children = array<Node*, 26>();
        bool is_end = false;
    };

    Node* root = new Node;

   public:
    int longestRepeatingSubstring(string s) {
        unordered_set<string> substrings;

        int result = 0;
        for (int l = 0; l < s.size(); ++l) {
            auto p = root;
            for (int r = l; r < s.size(); ++r) {
                int i = s[r] - 'a';

                Node* q = p->children[i];
                if (q == nullptr) {
                    q = p->children[i] = new Node;
                } else if (q->is_end) {
                    result = max(result, r - l + 1);
                }
                q->is_end = true;
                p = q;
            }
        }

        return result;
    }
};

class Solution {
    const int mod = 1e9 + 7;
    const int base = 26;

   public:
    int longestRepeatingSubstring(string s) {
        auto check = [&](int length) -> bool {
            if (length == 0) return true;

            long h = 0;
            long b = 1;
            for (int i = 0; i < length - 1; ++i) {
                long v = s[i] - 'a';

                h = h * base % mod;
                h = (h + v) % mod;

                b = b * base % mod;
            }

            unordered_set<int> seen;
            for (int i = length - 1; i < s.size(); ++i) {
                long v = s[i] - 'a';

                h = h * base % mod;
                h = (h + v) % mod;

                if (seen.count(h)) return true;
                seen.insert(h);

                long d = (s[i - length + 1] - 'a') * b % mod;
                h = (h - d + mod) % mod;
            }

            return false;
        };

        int l = 0, r = s.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l - 1;
    }
};
