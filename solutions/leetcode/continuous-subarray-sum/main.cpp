class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> seen;
        seen.insert(0);
        for (int i = 1, v = nums.front(); i < n; ++i) {
            v += nums[i];
            if (seen.count(v % k)) return true;
            seen.insert((v - nums[i]) % k);
        }
        return false;
    }
};

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp = {{0, -1}};
        for (int i = 0, v = 0; i < n; ++i) {
            v += nums[i];
            if (mp.count(v % k) && i >= mp[v % k] + 2) return true;
            mp.insert({v % k, i});
        }
        return false;
    }
};
