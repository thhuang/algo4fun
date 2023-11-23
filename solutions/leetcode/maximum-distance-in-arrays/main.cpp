class Solution {
   public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        int result = 0;

        deque<int> asc;
        for (int i = 1; i < n; ++i) {
            while (!asc.empty() && asc.back() > arrays[i].front()) {
                asc.pop_back();
            }
            asc.push_back(arrays[i].front());
        }
        for (int i = 0; i < n; ++i) {
            int mn = asc.front();
            int mx = arrays[i].back();
            result = max(result, mx - mn);

            if (i == n - 1) break;

            if (asc.front() == arrays[i + 1].front()) {
                asc.pop_front();
            }
            while (!asc.empty() && asc.back() > arrays[i].front()) {
                asc.pop_back();
            }
            asc.push_back(arrays[i].front());
        }

        deque<int> desc;
        for (int i = 1; i < n; ++i) {
            while (!desc.empty() && desc.back() > arrays[i].back()) {
                desc.pop_back();
            }
            desc.push_back(arrays[i].back());
        }
        for (int i = 0; i < n; ++i) {
            int mn = arrays[i].front();
            int mx = desc.front();
            result = max(result, mx - mn);

            if (i == n - 1) break;

            if (desc.front() == arrays[i + 1].back()) {
                desc.pop_front();
            }
            while (!desc.empty() && desc.back() < arrays[i].back()) {
                desc.pop_back();
            }
            desc.push_back(arrays[i].back());
        }

        return result;
    }
};
