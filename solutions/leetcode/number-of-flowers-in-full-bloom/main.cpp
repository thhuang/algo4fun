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

class Solution {
   public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& people) {
        vector<array<int, 2>> events;
        for (auto& in : flowers) {
            events.push_back({in[0], 0});
            events.push_back({in[1] + 1, 1});
        }
        for (int i : people) {
            events.push_back({i, 2});
        }

        sort(events.begin(), events.end());

        unordered_map<int, int> dayToFlowers;
        int cnt = 0;
        for (auto [d, ty] : events) {
            switch (ty) {
                case 0: {
                    ++cnt;
                    break;
                }
                case 1: {
                    --cnt;
                    break;
                }
                case 2: {
                    dayToFlowers[d] = cnt;
                    break;
                }
            }
        }

        vector<int> result;
        for (int d : people) {
            result.push_back(dayToFlowers[d]);
        }

        return result;
    }
};
