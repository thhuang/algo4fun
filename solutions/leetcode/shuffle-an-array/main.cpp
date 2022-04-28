class Solution {
    random_device rd_ = random_device();
    default_random_engine gen_;
    vector<int> nums_;

   public:
    Solution(vector<int>& nums) : nums_(nums), gen_(rd_()) {}

    vector<int> reset() { return nums_; }

    vector<int> shuffle() {
        vector<int> result = nums_;

        int n = nums_.size();
        for (int i = 0; i < n; ++i) {
            int j = uniform_int_distribution<int>(i, n - 1)(gen_);
            swap(result[i], result[j]);
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
