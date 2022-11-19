class Solution {
    int cross(vector<int>& a, vector<int>& b, vector<int>& c) {
        // u = b - a
        // v = c - b

        // u[0] u[1]
        // v[0] v[1]

        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }

   public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());

        deque<vector<int>> deq;
        for (vector<int>& t : trees) {
            while (deq.size() >= 2 &&
                   cross(deq[deq.size() - 2], deq[deq.size() - 1], t) < 0) {
                deq.pop_back();
            }
            deq.push_back(t);

            while (deq.size() >= 2 && cross(deq[1], deq[0], t) > 0) {
                deq.pop_front();
            }
            deq.push_front(t);
        }

        sort(deq.begin(), deq.end());

        return {deq.begin(), unique(deq.begin(), deq.end())};
    }
};
