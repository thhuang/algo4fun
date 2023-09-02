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

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        array<array<int, 2>, 26> charRange;
        charRange.fill({n - 1, 0});

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            auto& [l, r] = charRange[c - 'a'];
            l = min(l, i);
            r = max(r, i);
        }

        sort(charRange.begin(), charRange.end());

        vector<array<int, 2>> parts;
        for (auto [l, r] : charRange) {
            if (l > r) continue;
            if (parts.empty() || parts.back()[1] < l) {
                parts.push_back({l, r});
            } else {
                parts.back()[1] = max(parts.back()[1], r);
            }
        }

        vector<int> result;
        for (auto [l, r] : parts) {
            result.push_back(r - l + 1);
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        array<int, 26> charRight;
        charRight.fill(-1);
        for (int i = 0; i < s.size(); ++i) {
            charRight[s[i] - 'a'] = i;
        }

        vector<int> result;
        for (int i = 0, l = 0, r = -1; i < s.size(); ++i) {
            if (i > r) {
                l = i;
                result.push_back(0);
            }

            r = max(r, charRight[s[i] - 'a']);
            result.back() = r - l + 1;
        }

        return result;
    }
};

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        array<int, 26> charRight;
        charRight.fill(-1);
        for (int i = 0; i < s.size(); ++i) {
            charRight[s[i] - 'a'] = i;
        }

        vector<int> result;
        for (int i = 0, l = 0, r = 0; i < s.size(); ++i) {
            r = max(r, charRight[s[i] - 'a']);
            if (i < r) continue;
            result.push_back(r - l + 1);
            l = r + 1;
        }

        return result;
    }
};
