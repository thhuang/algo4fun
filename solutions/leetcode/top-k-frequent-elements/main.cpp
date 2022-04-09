class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> rank;
        vector<array<int, 2>> freq;
        for (int v : nums) {
            if (!rank.count(v)) {
                rank.insert({v, freq.size()});
                freq.push_back({v, 1});
                continue;
            }

            int i = rank.at(v);
            ++freq[i][1];
            while (i > 0 && freq[i - 1][1] < freq[i][1]) {
                swap(freq[i - 1], freq[i]);
                rank[freq[i - 1][0]] = i - 1;
                rank[freq[i][0]] = i;
                --i;
            }
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) result.push_back(freq[i][0]);

        return result;
    }
};
