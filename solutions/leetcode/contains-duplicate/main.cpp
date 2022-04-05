class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int v : nums) {
            if (seen.count(v)) return true;
            seen.insert(v);
        }
        return false;
    }
};

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) return true;
        }
        return false;
    }
};
