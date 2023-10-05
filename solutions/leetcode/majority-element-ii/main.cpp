class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int candidate0 = numeric_limits<int>::max(), count0 = 0;
        int candidate1 = numeric_limits<int>::max(), count1 = 0;

        for (int v : nums) {
            if (v == candidate0) {
                ++count0;
            } else if (v == candidate1) {
                ++count1;
            } else if (count0 == 0) {
                candidate0 = v;
                ++count0;
            } else if (count1 == 0) {
                candidate1 = v;
                ++count1;
            } else {
                --count0;
                --count1;
            }
        }

        count0 = count1 = 0;
        for (int v : nums) {
            count0 += v == candidate0;
            count1 += v == candidate1;
        }

        vector<int> result;
        if (count0 > n / 3) result.push_back(candidate0);
        if (count1 > n / 3) result.push_back(candidate1);
        return result;
    }
};
