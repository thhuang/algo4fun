class Solution {
   public:
    int minDeletions(string s) {
        unordered_map<char, int> char_freq;
        for (char c : s) ++char_freq[c];

        vector<int> nums;
        for (const auto [_, v] : char_freq) nums.push_back(v);
        sort(nums.begin(), nums.end(), greater<>());

        int result = 0;
        unordered_set<int> vis;
        for (int v : nums) {
            while (v > 0 && vis.count(v)) --v, ++result;
            vis.insert(v);
        }

        return result;
    }
};
