class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for (int l = 0; l < nums.size(); ++l) {
            int mn = numeric_limits<int>::max();
            int mx = numeric_limits<int>::min();

            for (int r = l; r < nums.size(); ++r) {
                mx = max(mx, nums[r]);
                mn = min(mn, nums[r]);
                result += mx - mn;
            }
        }
        return result;
    }
};

class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        auto subArraySum = [&](function<bool(int, int)> cmp) -> long long {
            vector<int> s;
            vector<int> right(n);
            for (int i = 0; i < n; ++i) {
                while (!s.empty() && cmp(nums[s.back()], nums[i])) {
                    right[s.back()] = i;
                    s.pop_back();
                }
                s.push_back(i);
            }
            for (int i : s) right[i] = n;

            s.clear();
            vector<int> left(n);
            for (int i = n - 1; i >= 0; --i) {
                while (!s.empty() && (cmp(nums[s.back()], nums[i]) ||
                                      nums[s.back()] == nums[i])) {
                    left[s.back()] = i;
                    s.pop_back();
                }
                s.push_back(i);
            }
            for (int i : s) left[i] = -1;

            long long result = 0;
            for (int i = 0; i < n; ++i)
                result += 1LL * nums[i] * (i - left[i]) * (right[i] - i);

            return result;
        };

        return subArraySum(less<int>()) - subArraySum(greater<int>());
    }
};
