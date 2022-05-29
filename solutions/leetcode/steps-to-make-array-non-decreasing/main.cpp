class Solution {
   public:
    int totalSteps(vector<int>& nums) {
        struct Entry {
            int val, steps;
        };

        vector<Entry> incr;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
            Entry entry = {*it, 0};
            while (!incr.empty() && *it > incr.back().val) {
                entry.steps = max(entry.steps + 1, incr.back().steps);
                incr.pop_back();
            }
            incr.push_back(entry);
        }

        int result = 0;
        for (const auto& entry : incr) result = max(result, entry.steps);

        return result;
    }
};
