class Solution {
   public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for (int v : amount) {
            if (v > 0) pq.push(v);
        }

        int count = 0;

        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();

            if (pq.empty()) return count + a;

            int b = pq.top();
            pq.pop();

            ++count;
            if (a > 1) pq.push(a - 1);
            if (b > 1) pq.push(b - 1);
        }

        return count;
    }
};

class Solution {
   public:
    int fillCups(vector<int>& amount) {
        int mx = 0, sum = 0;
        for (int v : amount) {
            mx = max(mx, v);
            sum += v;
        }
        return max(mx, (sum + 1) / 2);
    }
};
