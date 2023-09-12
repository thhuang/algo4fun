class Solution {
   public:
    int minDeletions(string s) {
        unordered_map<char, int> char_freq;
        for (char c : s) ++char_freq[c];

        vector<int> nums;
        for (const auto [_, v] : char_freq) nums.push_back(v);
        sort(nums.begin(), nums.end(), greater<>());

        int result = 0;
        unordered_set<int> vis;
        for (int v : nums) {
            while (v > 0 && vis.count(v)) --v, ++result;
            vis.insert(v);
        }

        return result;
    }
};

class Solution {
   public:
    int minDeletions(string s) {
        array<int, 26> charFreq;
        charFreq.fill(0);
        for (char c : s) ++charFreq[c - 'a'];

        map<int, int> freqCount;
        for (int i = 0; i < 26; ++i) ++freqCount[charFreq[i]];

        int result = 0;
        while (!freqCount.empty() && freqCount.rbegin()->first != 0) {
            auto it = --freqCount.end();
            auto [freq, cnt] = *it;
            freqCount.erase(it);

            result += --cnt;

            if (cnt > 0) freqCount[freq - 1] += cnt;
        }

        return result;
    }
};
