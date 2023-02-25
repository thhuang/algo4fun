class Solution {
   public:
    int minimumDeviation(vector<int>& nums) {
        int mn = numeric_limits<int>::max();

        priority_queue<int> pq;
        for (int v : nums) {
            if (v % 2 == 1) v <<= 1;
            mn = min(mn, v);
            pq.push(v);
        }

        int result = pq.top() - mn;

        while (pq.top() % 2 == 0) {
            int v = pq.top();
            pq.pop();

            v >>= 1;

            mn = min(mn, v);

            pq.push(v);
            result = min(result, pq.top() - mn);
        }

        return result;
    }
};
