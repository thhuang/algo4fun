class Solution {
   public:
    int minDeletion(vector<int>& nums) {
        int count = 0;
        int i = 0;
        int offset = 0;
        while (i + 1 + offset < size(nums)) {
            if (nums[i + offset] != nums[i + 1 + offset]) {
                i += 2;
                continue;
            }
            ++offset;
            ++count;
        }
        if ((size(nums) - offset) & 1) ++count;
        return count;
    }
};
