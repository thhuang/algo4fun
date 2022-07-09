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

class Solution {
   public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> scores(n, nums.front());
        deque<int> dq = {0};

        for (int i = 1; i < n; ++i) {
            while (dq.front() < i - k) dq.pop_front();
            scores[i] = scores[dq.front()] + nums[i];
            while (!dq.empty() && scores[dq.back()] <= scores[i]) dq.pop_back();
            dq.push_back(i);
        }

        return scores.back();
    }
};
