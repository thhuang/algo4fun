class Solution {
   public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        vector<int> memo(n, -1);
        function<int(int)> check = [&](int l) -> int {
            if (l == n) return 1;

            if (l + 1 == n) return 0;
            if (memo[l] != -1) return memo[l];
            if (nums[l] == nums[l + 1] && check(l + 2)) return memo[l] = 1;

            if (l + 2 == n) return false;
            int d1 = nums[l + 1] - nums[l];
            int d2 = nums[l + 2] - nums[l + 1];
            if ((d1 == 0 || d1 == 1) && d1 == d2) return memo[l] = check(l + 3);
            return memo[l] = 0;
        };

        return check(0) == 1;
    }
};
