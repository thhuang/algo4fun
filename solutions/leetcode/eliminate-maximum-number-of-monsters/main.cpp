class Solution {
   public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push((dist[i] - 1) / speed[i] + 1);
        }

        pq.pop();
        for (int t = 1; t < n; ++t) {
            if (t >= pq.top()) {
                return t;
            }
            pq.pop();
        }

        return n;
    }
};
