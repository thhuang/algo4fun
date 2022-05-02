class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return a % 2 < b % 2; });
        return nums;
    }
};

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        partition(nums.begin(), nums.end(),
                  [](int a) -> bool { return a % 2 == 0; });
        return nums;
    }
};
