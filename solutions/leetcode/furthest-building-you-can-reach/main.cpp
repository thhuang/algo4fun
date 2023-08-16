class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        vector<int> costs(n, 0);
        for (int i = 1; i < n; ++i)
            costs[i] = max(0, heights[i] - heights[i - 1]);

        multiset<int> low, high;
        long long sl = 0, sh = 0;
        for (int i = 0; i < n; ++i) {
            int c = costs[i];

            sl += c;
            low.insert(c);

            int u = *low.rbegin();
            sh += u;
            high.insert(u);
            sl -= u;
            low.erase(low.find(u));

            if (high.size() > ladders) {
                int v = *high.begin();
                sl += v;
                low.insert(v);
                sh -= v;
                high.erase(high.begin());
            }

            if (sl > bricks) return i - 1;
        }

        return n - 1;
    }
};

class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();

        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 1; i < n; ++i) {
            int d = heights[i] - heights[i - 1];
            if (d <= 0) continue;

            pq.push(d);
            if (pq.size() <= ladders) continue;

            bricks -= pq.top();
            pq.pop();

            if (bricks < 0) return i - 1;
        }

        return n - 1;
    }
};
