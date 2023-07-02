class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            if (sum < target) {
                ++l;
            } else {  // sum > target
                --r;
            }
        }
        return {};
    }
};

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum < target) {
                ++l;
            } else if (sum > target) {
                --r;
            } else {
                return {l + 1, r + 1};
            }
        }
        return {};
    }
};
