class Solution {
   public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q(piles.begin(), piles.end());
        for (int i = 0; i < k; ++i) {
            int v = q.top();
            q.pop();
            q.push((v + 1) / 2);
        }
        int result = 0;
        while (!q.empty()) {
            result += q.top();
            q.pop();
        }
        return result;
    }
};
