class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> window;
    for (int r = 0; r < nums.size(); ++r) {
      if (window.count(nums[r]))
        return true;
      window.insert(nums[r]);
      if (r - k >= 0)
        window.erase(nums[r - k]);
    }
    return false;
  }
};
