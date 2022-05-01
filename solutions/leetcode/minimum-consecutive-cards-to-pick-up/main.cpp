class Solution {
   public:
    int minimumCardPickup(vector<int>& cards) {
        int result = cards.size() + 1;

        unordered_map<int, int> num_idx;
        for (int i = 0; i < cards.size(); ++i) {
            int v = cards[i];
            auto it = num_idx.find(v);

            if (it != num_idx.end()) {
                int d = i - it->second + 1;
                result = min(result, d);
            }

            num_idx[v] = i;
        }

        if (result == cards.size() + 1) return -1;
        return result;
    }
};
