class Solution {
   public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        int n = nums.size();
        int m = l.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),
             [&](int i, int j) -> bool { return nums[i] < nums[j]; });

        vector<bool> result(m, true);

        for (int k = 0; k < m; ++k) {
            int left = l[k], right = r[k];
            vector<int> seq;
            for (int i : idx) {
                if (i < left || right < i) continue;
                seq.push_back(nums[i]);
            }
            int d = seq[1] - seq[0];
            for (int j = 2; j < seq.size(); ++j) {
                if (seq[j] - seq[j - 1] != d) {
                    result[k] = false;
                    break;
                }
            }
        }

        return result;
    }
};

class Solution {
   public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        int n = nums.size();
        int m = l.size();

        auto check = [&](int k) -> bool {
            int mn = numeric_limits<int>::max();
            int mx = numeric_limits<int>::min();
            unordered_set<int> vals;
            int cnt = 0;

            for (int i = l[k]; i <= r[k]; ++i) {
                int v = nums[i];
                mn = min(mn, v);
                mx = max(mx, v);
                vals.insert(v);
                ++cnt;
            }

            int d = (mx - mn) / (cnt - 1);
            if (mn + (cnt - 1) * d != mx) return false;

            for (int i = 1, v = mn; i < cnt; ++i) {
                v += d;
                if (vals.count(v) == 0) return false;
            }

            return true;
        };

        vector<bool> result;
        for (int k = 0; k < m; ++k) {
            result.push_back(check(k));
        }

        return result;
    }
};
