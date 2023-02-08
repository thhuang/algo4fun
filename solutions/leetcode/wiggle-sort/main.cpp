class Solution {
   public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // 0 <= 2 >= 1 <= 4 >= 3 <= 5
        for (int i = 1; i + 1 < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};
