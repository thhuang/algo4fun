class Solution {
   public:
    vector<int> sumEvenAfterQueries(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        int s = 0;
        for (int v : nums) {
            if (v % 2 == 0) s += v;
        }

        vector<int> result;
        for (const vector<int>& q : queries) {
            int i = q[1], v = q[0];

            if (nums[i] % 2 == 0) s -= nums[i];

            nums[i] += v;
            if (nums[i] % 2 == 0) s += nums[i];

            result.push_back(s);
        }

        return result;
    }
};
