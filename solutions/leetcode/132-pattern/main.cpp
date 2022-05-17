class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        vector<int> min_nums(nums.size());
        for (int i = 0, curr_min = numeric_limits<int>::max(); i < nums.size();
             ++i) {
            min_nums[i] = curr_min = min(curr_min, nums[i]);
        }

        vector<int> smallest_seen;
        for (int i = nums.size() - 1; ~i; --i) {
            while (!smallest_seen.empty() && smallest_seen.back() <= min_nums[i]) smallest_seen.pop_back();
            if (nums[i] == min_nums[i]) continue;
            if (!smallest_seen.empty() && nums[i] > smallest_seen.back()) return true;
            smallest_seen.push_back(nums[i]);
        }

        return false;
    }
};

class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        vector<int> min_num(n);
        for (int i = 0, mn = numeric_limits<int>::max(); i < n; ++i) {
            min_num[i] = mn = min(mn, nums[i]);
        }

        vector<int> decr;
        for (int i = n - 1; ~i; --i) {
            int v = nums[i];
            if (v == min_num[i]) continue;
            if (decr.empty() || decr.back() > v) decr.push_back(v);
            while (!decr.empty() && decr.back() <= min_num[i]) decr.pop_back();
            if (!decr.empty() && v > decr.back()) return true;
        }

        return false;
    }
};
