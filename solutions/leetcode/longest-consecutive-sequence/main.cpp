class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lr;
        unordered_map<int, int> rl;

        for (int v : nums) {
            int r = v;
            if (auto it = lr.find(v + 1); it != lr.end()) {
                r = max(r, it->second);
            }

            int l = v;
            if (auto it = rl.find(v - 1); it != rl.end()) {
                l = min(l, it->second);
            }

            lr[l] = lr.count(l) ? max(lr[l], r) : r;
            rl[r] = rl.count(r) ? min(rl[r], l) : l;
        }

        int result = 0;
        for (const auto [l, r] : lr) result = max(result, r - l + 1);

        return result;
    }
};

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int v : nums) numSet.insert(v);

        int result = 0;
        for (int l : nums) {
            if (numSet.count(l - 1) != 0) continue;
            int r = l;
            while (numSet.count(r) != 0) ++r;
            result = max(result, r - l);
        }

        return result;
    }
};
