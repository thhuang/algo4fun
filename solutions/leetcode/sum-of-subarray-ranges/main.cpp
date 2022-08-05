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
        vector<int> inc, dec;
        vector<array<int, 2>> right(n), left(n);

        for (int i = 0; i < n; ++i) {
            int v = nums[i];

            while (!inc.empty() && nums[inc.back()] > v) {
                right[inc.back()][0] = i;
                inc.pop_back();
            }
            inc.push_back(i);

            while (!dec.empty() && nums[dec.back()] < v) {
                right[dec.back()][1] = i;
                dec.pop_back();
            }
            dec.push_back(i);
        }
        for (int i : inc) right[i][0] = n;
        for (int i : dec) right[i][1] = n;

        inc.clear();
        dec.clear();

        for (int i = n - 1; i >= 0; --i) {
            int v = nums[i];

            while (!inc.empty() && nums[inc.back()] >= v) {
                left[inc.back()][0] = i;
                inc.pop_back();
            }
            inc.push_back(i);

            while (!dec.empty() && nums[dec.back()] <= v) {
                left[dec.back()][1] = i;
                dec.pop_back();
            }
            dec.push_back(i);
        }
        for (int i : inc) left[i][0] = -1;
        for (int i : dec) left[i][1] = -1;

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result += 1LL * nums[i] * (i - left[i][1]) * (right[i][1] - i);
            result -= 1LL * nums[i] * (i - left[i][0]) * (right[i][0] - i);
        }

        return result;
    }
};
