class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int v : nums) {
            if (auto it = lower_bound(sub.begin(), sub.end(), v);
                it == sub.end()) {
                sub.push_back(v);
            } else {
                *it = v;
            }
        }
        return sub.size();
    }
};
