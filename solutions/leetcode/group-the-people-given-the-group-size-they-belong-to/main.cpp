class Solution {
   public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> sizeToPeople;
        for (int i = 0; i < groupSizes.size(); ++i) {
            sizeToPeople[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> result;
        for (auto [sz, people] : sizeToPeople) {
            while (!people.empty()) {
                result.push_back({});
                for (int i = 0; i < sz; ++i) {
                    result.back().push_back(people.back());
                    people.pop_back();
                }
            }
        }

        return result;
    }
};
