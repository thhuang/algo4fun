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

class Solution {
    int index(int v, int w) { return v >= 0 ? v / w : (v + 1) / w - 1; }

   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        int w = valueDiff + 1;
        unordered_map<int, int> buckets;

        for (int r = 0, l = r - indexDiff; r < nums.size(); ++l, ++r) {
            int i = index(nums[r], w);

            if (buckets.count(i) > 0) return true;
            if (buckets.count(i - 1) && abs(buckets[i - 1] - nums[r]) < w)
                return true;
            if (buckets.count(i + 1) && abs(buckets[i + 1] - nums[r]) < w)
                return true;

            buckets[i] = nums[r];

            if (l < 0) continue;

            buckets.erase(index(nums[l], w));
        }

        return false;
    }
};
