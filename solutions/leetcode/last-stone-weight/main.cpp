class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int s : stones) q.push(s);

        while (!q.empty()) {
            int a = q.top();
            q.pop();
            if (q.empty()) return a;
            int b = q.top();
            q.pop();

            if (a == b) continue;
            q.push(abs(a - b));
        }

        return 0;
    }
};
