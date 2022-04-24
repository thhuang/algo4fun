class Solution {
   public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& persons) {
        vector<int> starts;
        vector<int> ends;
        for (const auto& fl : flowers) {
            starts.push_back(fl[0]);
            ends.push_back(fl[1] + 1);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> result(persons.size());
        for (int i = 0; i < persons.size(); ++i) {
            int t = persons[i];
            int s = upper_bound(starts.begin(), starts.end(), t) -
                    starts.begin() - 1;
            int e = upper_bound(ends.begin(), ends.end(), t) - ends.begin() - 1;
            result[i] = s - e;
        }

        return result;
    }
};
