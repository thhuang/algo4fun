class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> score(n, -1e9);
        multiset<int> window;

        score.front() = nums.front();
        window.emplace(score.front());

        for (int i = 1; i < n; ++i) {
            score[i] = *window.rbegin() + nums[i];
            window.emplace(score[i]);
            if (window.size() > k) window.erase(window.find(score[i - k]));
        }

        return score.back();
    }
};
