class Solution {
    unordered_map<int, vector<int>> val2idx;

   public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) val2idx[nums[i]].push_back(i);
    }

    int pick(int target) {
        vector<int>& indices = val2idx[target];
        int n = indices.size();
        int b = numeric_limits<int>::max() % n;

        int r = random();
        while (r <= b) r = random();

        return indices[r % n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
