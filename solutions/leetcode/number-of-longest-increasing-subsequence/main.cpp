class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 2>> length_count(n, {0, 0});
        int max_length = 0;

        for (int r = 0; r < n; ++r) {
            int max_prefix_length = 0;
            int count = 1;
            for (int l = 0; l < r; ++l) {
                if (nums[r] <= nums[l]) continue;
                if (length_count[l][0] < max_prefix_length) continue;
                if (length_count[l][0] == max_prefix_length) {
                    count += length_count[l][1];
                } else {  // length[l][0] > max_prefix_length
                    max_prefix_length = length_count[l][0];
                    count = length_count[l][1];
                }
            }

            int length = max_prefix_length + 1;
            length_count[r] = {length, count};
            max_length = max(max_length, length);
        }

        int result = 0;
        for (const auto& p : length_count) {
            if (p[0] == max_length) result += p[1];
        }

        return result;
    }
};

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> len(n, 1), cnt(n, 1);
        len[0] = 1, cnt[0] = 1;

        for (int r = 1; r < n; ++r) {
            int mxLen = 1, mxCnt = 1;
            for (int l = 0; l < r; ++l) {
                if (nums[l] >= nums[r]) continue;

                if (len[l] + 1 > mxLen) {
                    mxLen = len[l] + 1;
                    mxCnt = cnt[l];
                } else if (len[l] + 1 == mxLen) {
                    mxCnt += cnt[l];
                }
            }
            len[r] = mxLen, cnt[r] = mxCnt;
        }

        int result = 0;
        int mxLen = *max_element(len.begin(), len.end());
        for (int i = 0; i < n; ++i) {
            if (len[i] == mxLen) result += cnt[i];
        }

        return result;
    }
};
