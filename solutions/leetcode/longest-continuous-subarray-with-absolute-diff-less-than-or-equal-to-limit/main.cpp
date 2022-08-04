class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> inc, dec;
        int result = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (!inc.empty() && nums[inc.back()] > nums[r]) inc.pop_back();
            inc.push_back(r);

            while (!dec.empty() && nums[dec.back()] < nums[r]) dec.pop_back();
            dec.push_back(r);

            while (l <= r && nums[dec.front()] - nums[inc.front()] > limit) {
                if (inc.front() == l) inc.pop_front();
                if (dec.front() == l) dec.pop_front();
                ++l;
            }

            result = max(result, r - l + 1);
        }
        return result;
    }
};
