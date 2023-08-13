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

class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1) return {};

        int mx = *max_element(changed.begin(), changed.end());
        vector<int> buckets(mx + 1, 0);

        for (int v : changed) ++buckets[v];

        vector<int> result;
        for (int i = mx; i >= 0; --i) {
            if (buckets[i] == 0) continue;
            if (i % 2 == 1) return {};
            --buckets[i];

            if (buckets[i / 2] == 0) return {};
            --buckets[i / 2];
            result.push_back(i / 2);

            ++i;
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> numCount;
        for (int v : changed) ++numCount[v];

        vector<int> result;
        while (!numCount.empty()) {
            auto it = numCount.begin();
            auto [single, cnt] = *it;

            if (single == 0) {
                if (cnt % 2 != 0) return {};

                numCount.erase(0);
                for (int i = 0; i < cnt / 2; ++i) result.push_back(0);

                continue;
            }

            int doubled = single * 2;
            if (int v = numCount[doubled] -= cnt; v < 0) {
                return {};
            } else if (v == 0) {
                numCount.erase(doubled);
            }
            numCount.erase(it);
            for (int i = 0; i < cnt; ++i) result.push_back(single);
        }

        return result;
    }
};
