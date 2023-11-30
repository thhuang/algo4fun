class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) left[i] = 1 + (i > 0 ? left[i - 1] : 0);
        }
        for (int i = n - 1; ~i; --i) {
            if (nums[i] == 1) right[i] = 1 + (i + 1 < n ? right[i + 1] : 0);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            int v = 1;
            if (i > 0) v += left[i - 1];
            if (i + 1 < n) v += right[i + 1];
            result = max(result, v);
        }

        return result;
    }
};

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        bool has_zero = false;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                if (has_zero) {
                    while (nums[l++] == 1)
                        ;
                }
                has_zero = true;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};

class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int l = 0, r = 0, flipped = 0; r < n; ++r) {
            if (nums[r] == 0) ++flipped;
            while (flipped > 1) {
                if (nums[l++] == 0) --flipped;
            }
            result = max(result, r - l + 1);
        }
        return result;
    }
};
