class Solution {
   public:
    bool sequenceReconstruction(vector<int>& nums,
                                vector<vector<int>>& sequences) {
        int n = nums.size();

        vector<int> numToIdx(n + 1);
        for (int i = 0; i < n; ++i) {
            numToIdx[nums[i]] = i;
        }

        vector<bool> checked(n, false);
        for (vector<int>& sequence : sequences) {
            int m = sequence.size();
            for (int i = 1; i < m; ++i) {
                int a = sequence[i - 1];
                int b = sequence[i];
                if (numToIdx[a] > numToIdx[b]) return false;
                if (numToIdx[a] + 1 == numToIdx[b]) {
                    checked[numToIdx[a]] = true;
                }
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            if (!checked[i]) return false;
        }

        return true;
    }
};
