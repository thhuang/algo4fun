class Solution {
   public:
    vector<int> intersection(vector<vector<int>>& nums) {
        deque<int> result;
        for (int v : nums.front()) result.push_back(v);

        for (vector<int>& vec : nums) {
            unordered_set<int> next_s;
            for (int v : vec) next_s.insert(v);

            auto it = result.begin();
            while (it != result.end()) {
                if (next_s.count(*it) == 0) {
                    it = result.erase(it);
                } else {
                    ++it;
                }
            }
        }

        sort(result.begin(), result.end());

        return {result.begin(), result.end()};
    }
};
