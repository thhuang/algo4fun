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
        vector<int> result;

        multiset<int> inc;
        for (int r = 0, l = -k + 1; r < nums.size(); ++l, ++r) {
            inc.insert(nums[r]);

            if (l < 0) continue;

            result.push_back(*inc.rbegin());

            inc.erase(inc.find(nums[l]));
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

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        deque<int> desc;
        for (int l = -k + 1, r = 0; r < nums.size(); ++l, ++r) {
            while (!desc.empty() && desc.back() < nums[r]) desc.pop_back();
            desc.push_back(nums[r]);

            if (l < 0) continue;

            result.push_back(desc.front());

            if (nums[l] == desc.front()) desc.pop_front();
        }

        return result;
    }
};
