class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) return {};

        multiset<int> vals(changed.begin(), changed.end());

        vector<int> result;
        while (!vals.empty()) {
            int mx = *vals.rbegin();
            vals.erase(vals.find(mx));
            if (mx % 2 == 1) return {};

            auto it = vals.find(mx / 2);
            if (it == vals.end()) return {};
            result.push_back(*it);
            vals.erase(it);
        }

        return result;
    }
};
