
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        struct State {
            int maximum, minimum;
        };

        int result = nums[0];
        State state = {nums[0], nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            array<int, 3> candidates = {nums[i] * state.maximum,
                                        nums[i] * state.minimum, nums[i]};
            state = {*max_element(candidates.begin(), candidates.end()),
                     *min_element(candidates.begin(), candidates.end())};
            result = max(result, state.maximum);
        }

        return result;
    }
};

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        struct DP {
            int pos, neg;
        };

        int result = numeric_limits<int>::min();
        DP dp = {-1, 1};
        for (int v : nums) {
            if (v >= 0) dp = {max(v, dp.pos * v), dp.neg * v};
            if (v <= 0) dp = {v * dp.neg, min(v, dp.pos * v)};
            result = dp.pos >= 0 ? max(result, dp.pos) : max(result, dp.neg);
        }

        return result;
    }
};

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];

        for (int i = 1, mn = nums[0], mx = nums[0]; i < nums.size(); ++i) {
            int v = nums[i];
            array<int, 3> candidates = {v, mx * v, mn * v};
            mx = *max_element(candidates.begin(), candidates.end());
            mn = *min_element(candidates.begin(), candidates.end());
            result = max(result, mx);
        }

        return result;
    }
};

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];

        for (int i = 1, mn = nums[0], mx = nums[0]; i < nums.size(); ++i) {
            int v = nums[i];
            array<int, 3> candidates = {v, mx * v, mn * v};
            sort(candidates.begin(), candidates.end());
            mx = candidates[2];
            mn = candidates[0];
            result = max(result, mx);
        }

        return result;
    }
};
