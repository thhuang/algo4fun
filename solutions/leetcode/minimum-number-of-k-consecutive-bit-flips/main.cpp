class Solution {
   public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        bool flipped = false;
        vector<bool> flip(n, false);

        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) flipped ^= flip[i - k];
            if (flipped != nums[i]) continue;
            if (i + k > n) return -1;
            flip[i] = true;
            flipped = !flipped;
            ++count;
        }

        return count;
    }
};
