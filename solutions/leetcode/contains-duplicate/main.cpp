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
