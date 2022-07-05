class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int v : nums) num_set.insert(v);

        int result = 0;
        for (int v : nums) {
            if (num_set.count(v - 1)) continue;
            int length = 1;
            while (num_set.count(++v)) ++length;
            result = max(result, length);
        }

        return result;
    }
};

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
