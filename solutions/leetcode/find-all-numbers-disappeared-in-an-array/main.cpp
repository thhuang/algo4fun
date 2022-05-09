class Solution {
   public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1) {
                int i0 = i, i1 = nums[i] - 1;
                if (nums[i0] == nums[i1]) break;
                swap(nums[i0], nums[i1]);
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) result.push_back(i + 1);
        }

        return result;
    }
};
