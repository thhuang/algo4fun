class Solution {
    const int mod = 1e9 + 7;

   public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i) {
            string s = to_string(nums[i]);
            int r = stoi(string{s.rbegin(), s.rend()});
            ++freq[nums[i] - r];
        }
        long long result = 0;
        for (auto [_, v] : freq) {
            (result += (long long)v * (v - 1) / 2) %= mod;
        }
        return result;
    }
};
