class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        struct Curr {
            int max, min;
        };

        int ans = nums[0];
        Curr curr = {nums[0], nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            array<int, 3> candidates = {curr.max * nums[i], curr.min * nums[i],
                                        nums[i]};
            curr = {*max_element(candidates.begin(), candidates.end()),
                    *min_element(candidates.begin(), candidates.end())};
            ans = max(ans, curr.max);
        }

        return ans;
    }
};
