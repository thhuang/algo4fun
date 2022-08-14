class Solution {
   public:
    int countSpecialNumbers(int n) {
        vector<int> nums;
        for (char c : to_string(n)) nums.push_back(c - '0');
        int sz = nums.size();

        int count = 0;
        for (int i = 1, v = 9; i < sz; ++i) {
            count += v;
            v *= (10 - i);
        }

        vector<vector<int>> cache(sz + 1, vector<int>(sz + 1, -1));
        auto cal = [&cache, &sz](int fix, int var) -> int {
            if (cache[fix][var] != -1) return cache[fix][var];
            int v = 1;
            for (int i = 0; i < var; ++i) {
                v *= (10 - fix - i);
            }
            return cache[fix][var] = v;
        };

        vector<bool> seen(10, false);
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                if (i == 0 && j == 0) continue;
                if (seen[j]) continue;
                count += cal(i + 1, sz - i - 1);
            }

            if (seen[nums[i]]) break;
            seen[nums[i]] = true;
        }

        if (unordered_set(nums.begin(), nums.end()).size() == nums.size())
            ++count;

        return count;
    }
};
