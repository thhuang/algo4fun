class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for (int v : nums) {
            auto it = lower_bound(seq.begin(), seq.end(), v);
            if (it == seq.end()) {
                seq.push_back(v);
            } else {
                *it = v;
            }
        }
        return seq.size();
    }
};
