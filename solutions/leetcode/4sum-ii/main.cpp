class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> sum_count_12;
        for (int a : nums1) {
            for (int b : nums2) {
                ++sum_count_12[a + b];
            }
        }

        unordered_map<int, int> sum_count_34;
        for (int a : nums3) {
            for (int b : nums4) {
                ++sum_count_34[a + b];
            }
        }

        int count = 0;
        for (auto [sum12, count12] : sum_count_12) {
            count += sum_count_34[-sum12] * count12;
        }

        return count;
    }
};

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> sum_count;
        for (int a : nums1) {
            for (int b : nums2) {
                ++sum_count[a + b];
            }
        }

        int count = 0;
        for (int a : nums3) {
            for (int b : nums4) {
                count += sum_count[-(a + b)];
            }
        }

        return count;
    }
};
