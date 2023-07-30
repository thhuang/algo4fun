class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> inc;
        for (int v : nums) {
            auto it = lower_bound(inc.begin(), inc.end(), v);
            if (it == inc.end()) {
                inc.push_back(v);
            } else {
                *it = v;
            }
        }
        return inc.size();
    }
};
