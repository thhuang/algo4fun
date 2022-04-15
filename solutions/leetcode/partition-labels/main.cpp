class Solution {
   public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, array<int, 2>> char_range;
        for (int i = 0; i < s.size(); ++i) {
            if (auto it = char_range.find(s[i]); it == char_range.end()) {
                char_range[s[i]] = {i, i};
            } else {
                it->second[1] = i;
            }
        }

        vector<array<int, 2>> intervals;
        for (auto it = char_range.begin(); it != char_range.end(); ++it)
            intervals.push_back(it->second);
        sort(intervals.begin(), intervals.end());

        vector<int> result;
        int l = 0, r = 0;
        for (auto interval : intervals) {
            if (interval[0] <= r) {
                r = max(r, interval[1]);
            } else {
                result.push_back(r - l + 1);
                l = interval[0];
                r = interval[1];
            }
        }
        result.push_back({r - l + 1});

        return result;
    }
};
