class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int v : nums) num_set.insert(v);

        int result = 0;
        for (int v : nums) {
            if (num_set.count(v - 1)) continue;
            int length = 1;
            while (num_set.count(++v)) ++length;
            result = max(result, length);
        }

        return result;
    }
};
