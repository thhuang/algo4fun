class Solution {
   public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<>> pq(sticks.begin(),
                                                       sticks.end());
        int result = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            result += a + b;
            pq.push(a + b);
        }
        return result;
    }
};
