class Solution {
   public:
    bool verifyPreorder(vector<int>& preorder) {
        function<bool(int, int, int, int)> verify = [&](int l, int r, int lv,
                                                        int rv) -> bool {
            if (r < l) return true;
            if (preorder[l] < lv || rv < preorder[l]) return false;

            auto m = upper_bound(preorder.begin() + l + 1,
                                 preorder.begin() + r + 1, preorder[l]) -
                     preorder.begin();

            if (!verify(l + 1, m - 1, lv, preorder[l] - 1)) return false;
            if (!verify(m, r, preorder[l] + 1, rv)) return false;

            return true;
        };

        return verify(0, preorder.size() - 1, numeric_limits<int>::min(),
                      numeric_limits<int>::max());
    }
};

class Solution {
   public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = numeric_limits<int>::min();
        vector<int> desc;
        for (int v : preorder) {
            while (!desc.empty() && desc.back() < v) {
                minLimit = max(minLimit, desc.back());
                desc.pop_back();
            }
            if (v < minLimit) return false;
            desc.push_back(v);
        }
        return true;
    }
};

class Solution {
   public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = numeric_limits<int>::min();
        int i = 0;
        for (int v : preorder) {
            while (i > 0 && preorder[i - 1] < v) {
                minLimit = max(minLimit, preorder[i - 1]);
                --i;
            }
            if (v < minLimit) return false;
            preorder[i++] = v;
        }
        return true;
    }
};
