class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> triplet;
        for (int v : nums) {
            auto it = lower_bound(triplet.begin(), triplet.end(), v);
            if (it == triplet.end()) {
                triplet.push_back(v);
                if (triplet.size() == 3) return true;
                continue;
            }
            *it = v;
        }
        return false;
    }
};
