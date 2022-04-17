class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> num_count;
        for (int v : nums) ++num_count[v];

        vector<vector<int>> result;
        vector<int> subset;
        function<void(unordered_map<int, int>::iterator)> search =
            [&](unordered_map<int, int>::iterator it) -> void {
            if (it == num_count.end()) {
                result.push_back(subset);
                return;
            }
            auto next_it = it;
            ++next_it;
            search(next_it);
            for (int j = 0; j < it->second; ++j) {
                subset.push_back(it->first);
                search(next_it);
            }
            for (int j = 0; j < it->second; ++j) subset.pop_back();
        };

        search(num_count.begin());

        return result;
    }
};
