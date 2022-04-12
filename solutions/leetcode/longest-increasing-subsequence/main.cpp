class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subsequence;
        for (int v : nums) {
            auto it = lower_bound(subsequence.begin(), subsequence.end(), v);
            if (it == subsequence.end()) {
                subsequence.push_back(v);
            } else {
                *it = v;
            }
        }
        return subsequence.size();
    }
};
