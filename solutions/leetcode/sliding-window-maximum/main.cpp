class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        for (int i = 0; i < k - 1; ++i) window.insert(nums[i]);

        vector<int> result;
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);
            result.push_back(*window.rbegin());
            window.erase(window.find(nums[i - k + 1]));
        }

        return result;
    }
};
