class Solution {
   public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> task_count;
        for (int v : tasks) ++task_count[v];

        int result = 0;
        for (auto [_, c] : task_count) {
            if (c == 1) return -1;
            result += c / 3;
            if (c % 3 > 0) ++result;
        }

        return result;
    }
};
