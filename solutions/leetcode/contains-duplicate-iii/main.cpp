class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        map<int, int> window;

        for (int r = 0, l = r - indexDiff; r < nums.size(); ++l, ++r) {
            int cnt = ++window[nums[r]];
            if (cnt > 1) return true;

            auto it = window.find(nums[r]);
            if (it->first != window.begin()->first &&
                it->first - prev(it)->first <= valueDiff)
                return true;
            if (it->first != window.rbegin()->first &&
                next(it)->first - it->first <= valueDiff)
                return true;

            if (l < 0) continue;

            if (--window[nums[l]] == 0) {
                window.erase(nums[l]);
            }
        }

        return false;
    }
};
