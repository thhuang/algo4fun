class Solution {
   public:
    long long kSum(vector<int>& nums, int k) {
        long long result = 0;
        vector<int> abs_nums;
        for (int v : nums) {
            if (v > 0) result += v;
            abs_nums.push_back(abs(v));
        }

        sort(abs_nums.begin(), abs_nums.end());

        priority_queue<pair<long long, int>> pq;
        pq.push({result - abs_nums[0], 0});

        for (int i = 1; i < k; ++i) {
            auto [sum, j] = pq.top();
            pq.pop();

            result = sum;

            if (j + 1 == abs_nums.size()) continue;
            pq.push({sum + abs_nums[j] - abs_nums[j + 1], j + 1});
            pq.push({sum - abs_nums[j + 1], j + 1});
        }

        return result;
    }
};
