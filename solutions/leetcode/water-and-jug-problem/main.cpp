class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity,
                         int targetCapacity) {
        int n = jug1Capacity + jug2Capacity;
        vector<bool> vis(n, false);
        deque<int> q = {0};

        while (!q.empty()) {
            int i = q.front();
            q.pop_front();

            if (i == targetCapacity) return true;
            if (i < 0 || i >= n) continue;
            if (vis[i]) continue;

            vis[i] = true;

            q.push_back(i + jug1Capacity);
            q.push_back(i - jug1Capacity);
            q.push_back(i + jug2Capacity);
            q.push_back(i - jug2Capacity);
        }

        return false;
    }
};

class Solution {
   public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity,
                         int targetCapacity) {
        if (targetCapacity > jug1Capacity + jug2Capacity) return false;
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};
