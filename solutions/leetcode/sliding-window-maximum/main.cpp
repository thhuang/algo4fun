class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        for (int i = 0; i < k - 1; ++i) window.insert(nums[i]);

        vector<int> result;
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);
            result.push_back(*window.rbegin());
            window.erase(window.find(nums[i - k + 1]));
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;

        auto push = [&](int v) -> int {
            while (!q.empty() && q.back() < v) q.pop_back();
            q.push_back(v);
            return q.front();
        };

        auto pop = [&](int v) -> void {
            if (v == q.front()) q.pop_front();
        };

        for (int i = 0; i < k - 1; ++i) push(nums[i]);

        vector<int> result;
        for (int i = k - 1; i < nums.size(); ++i) {
            result.push_back(push(nums[i]));
            pop(nums[i - k + 1]);
        }

        return result;
    }
};
