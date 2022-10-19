class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_count;
        for (const string& w : words) ++word_count[w];

        auto cmp = [](const pair<int, string>& a,
                      const pair<int, string>& b) -> bool {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq(cmp);

        for (const auto& [w, c] : word_count) pq.push({c, w});

        vector<string> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = pq.top().second;
            pq.pop();
        }

        return result;
    }
};
