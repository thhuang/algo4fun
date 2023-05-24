class Solution {
   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<array<int, 2>> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = {nums2[i], nums1[i]};

        sort(nums.begin(), nums.end(), greater<>());

        long long result = 0;

        priority_queue<int, vector<int>, greater<>> pq;
        long long curr = 0;
        for (int i = 0; i < n; ++i) {
            int v1 = nums[i][1];
            int v2 = nums[i][0];

            if (pq.size() == k) {
                int t = pq.top();
                pq.pop();
                curr -= t;
                v1 = max(v1, t);
            }

            pq.push(v1);
            curr += v1;

            if (pq.size() == k) result = max(result, curr * v2);
        }

        return result;
    }
};

class Solution {
   public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<array<int, 2>> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = {nums2[i], nums1[i]};

        sort(nums.begin(), nums.end(), greater<>());

        long long result = 0;
        long long curr = 0;
        priority_queue<int, vector<int>, greater<>> pq;

        for (int i = 0; i < n; ++i) {
            int v1 = nums[i][1];
            int v2 = nums[i][0];

            pq.push(v1);
            curr += v1;

            if (pq.size() > k) {
                curr -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                result = max(result, curr * v2);
            }
        }

        return result;
    }
};
