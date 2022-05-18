class Solution {
   public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix_sum(n);
        for (long i = 0, s = 0; i < n; ++i) {
            prefix_sum[i] = s += nums[i];
        }

        int result = numeric_limits<int>::max();
        deque<int> incr_index;
        for (int i = 0; i < n; ++i) {
            if (prefix_sum[i] >= k) {
                result = min(result, i + 1);
            }
            while (!incr_index.empty() &&
                   prefix_sum[i] - prefix_sum[incr_index.front()] >= k) {
                result = min(result, i - incr_index.front());
                incr_index.pop_front();
            }
            while (!incr_index.empty() &&
                   prefix_sum[incr_index.back()] >= prefix_sum[i]) {
                incr_index.pop_back();
            }
            incr_index.push_back(i);
        }

        return result > n ? -1 : result;
    }
};

class Solution {
   public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix_sum = {0};
        for (int v : nums) prefix_sum.push_back(prefix_sum.back() + v);

        deque<int> incr = {0};
        int result = numeric_limits<int>::max();

        for (int i = 1; i <= n; ++i) {
            while (!incr.empty() && prefix_sum[incr.back()] >= prefix_sum[i])
                incr.pop_back();
            while (!incr.empty() &&
                   prefix_sum[i] - prefix_sum[incr.front()] >= k) {
                result = min(result, i - incr.front());
                incr.pop_front();
            }
            incr.push_back(i);
        }

        return result > n ? -1 : result;
    }
};
