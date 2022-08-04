class Solution {
   public:
    int getMaxLen(vector<int>& nums) {
        struct DP {
            int pos, neg;
        };

        int max_pos = 0;
        DP dp = {0, 0};
        for (int v : nums) {
            if (v > 0) {
                dp = {dp.pos + 1, dp.neg ? dp.neg + 1 : 0};
            } else if (v < 0) {
                dp = {dp.neg ? dp.neg + 1 : 0, dp.pos + 1};
            } else {
                dp = {0, 0};
            }
            max_pos = max(max_pos, dp.pos);
        }
        return max_pos;
    }
};

class Solution {
    int search(const vector<int>& nums, int l, int r) {
        vector<int> negs;
        for (int i = l; i < r; ++i) {
            if (nums[i] < 0) negs.push_back(i);
        }
        if (negs.size() % 2 == 0) return r - l;
        return r - l - min(negs.front() - l + 1, r - negs.back());
    }

   public:
    int getMaxLen(vector<int>& nums) {
        int result = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] != 0) continue;
            result = max(result, search(nums, l, r));
            l = r + 1;
        }
        return max(result, search(nums, l, nums.size()));
    }
};
