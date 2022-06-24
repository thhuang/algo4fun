class Solution {
   public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for (int v : target) {
            sum += v;
            pq.push(v);
        }

        while (sum > target.size()) {
            long long new_sum = pq.top();
            pq.pop();

            int v = new_sum * 2 - sum;
            if (v < 1 || new_sum <= v || pq.empty()) return false;

            int next_val = pq.top();
            if (v > next_val) {
                int diff = new_sum - v;
                int sub = diff * ((v - next_val) / diff);
                v -= sub;
                new_sum -= sub;
            }

            pq.push(v);
            sum = new_sum;
        }

        return sum == target.size();
    }
};
