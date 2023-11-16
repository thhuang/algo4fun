class Solution {
   public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        unordered_set<string> exists(nums.begin(), nums.end());

        for (int i = 0; i <= 16; ++i) {
            string s = bitset<16>(i).to_string().substr(16 - m);
            if (exists.count(s) > 0) continue;
            return s;
        }

        return string(m, '1');
    }
};

class Solution {
   public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result;
        for (int i = 0; i < n; ++i) {
            result += (nums[i][i] == '0' ? '1' : '0');
        }
        return result;
    }
};
