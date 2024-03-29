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
        unordered_set<int> numbers;
        for (int v : nums) numbers.insert(v);

        int result = 0;

        for (int l : numbers) {
            if (numbers.count(l - 1) != 0) continue;
            int r = l + 1;
            while (numbers.count(r) != 0) ++r;
            result = max(result, r - l);
        }

        return result;
    }
};

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());

        int result = 0;

        for (int v : mp) {
            if (mp.count(v - 1) != 0) continue;
            int cnt = 0;
            while (mp.count(v++) != 0) ++cnt;
            result = max(result, cnt);
        }

        return result;
    }
};
