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

class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> curr;

        function<void(int)> search = [&](int i) -> void {
            if (i == nums.size()) {
                result.push_back(curr);
                return;
            }

            curr.push_back(nums[i]);
            search(i + 1);
            curr.pop_back();

            int j = i + 1;
            while (j < nums.size() && nums[i] == nums[j]) ++j;
            search(j);
        };

        search(0);

        return result;
    }
};
