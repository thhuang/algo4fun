class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        deque<int> neg_sq, pos_sq;
        for (int v : nums) {
            if (v < 0) {
                neg_sq.push_front(v * v);
            } else {
                pos_sq.push_back(v * v);
            }
        }

        vector<int> result;
        while (neg_sq.size() && pos_sq.size()) {
            if (neg_sq.front() < pos_sq.front()) {
                result.push_back(neg_sq.front());
                neg_sq.pop_front();
            } else {
                result.push_back(pos_sq.front());
                pos_sq.pop_front();
            }
        }

        while (neg_sq.size())
            result.push_back(neg_sq.front()), neg_sq.pop_front();
        while (pos_sqsize())
            result.push_back(pos_sq.front()), pos_sq.pop_front();

        return result;
    }
};
