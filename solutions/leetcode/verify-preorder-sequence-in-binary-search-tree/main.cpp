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
