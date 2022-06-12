class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0;
        int sum = 0;
        unordered_set<int> window;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            int v = nums[r];

            if (window.count(v) == 0) {
                window.insert(v);
                sum += v;
                result = max(result, sum);
                continue;
            }

            while (nums[l] != v) {
                window.erase(nums[l]);
                sum -= nums[l++];
            }
            ++l;
        }
        return result;
    }
};

class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> prefix_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        int result = 0;
        unordered_map<int, int> last_index;
        int l = -1;
        for (int i = 0; i < nums.size(); ++i) {
            int v = nums[i];
            if (auto it = last_index.find(v); it != last_index.end()) {
                l = max(l, it->second);
            }
            result = max(result, prefix_sum[i + 1] - prefix_sum[l + 1]);
            last_index[v] = i;
        }

        return result;
    }
};
