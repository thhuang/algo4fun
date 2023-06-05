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

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int a = numeric_limits<int>::max();
        int b = numeric_limits<int>::max();
        for (int v : nums) {
            if (v <= a) {
                a = v;
            } else if (v <= b) {
                b = v;
            } else {
                return true;
            }
        }
        return false;
    }
};
