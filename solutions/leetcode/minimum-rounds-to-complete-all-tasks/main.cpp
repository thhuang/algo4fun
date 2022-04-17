class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> level_count;
        for (int t : tasks) ++level_count[t];
        int count = 0;
        for (auto it = level_count.begin(); it != level_count.end(); ++it) {
            if (it->second == 1) return -1;
            count += it->second / 3;
            if (it->second % 3 != 0) ++count;
        }
        return count;
    }
};
