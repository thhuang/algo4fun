class Solution {
   public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();

        unordered_map<string, int> count;
        for (int i = 0; i < n; ++i) {
            stringstream ss(messages[i]);
            string w;
            while (ss >> w) ++count[senders[i]];
        }

        vector<pair<int, string>> vec;
        for (const auto& p : count) vec.push_back({p.second, p.first});

        sort(vec.begin(), vec.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 if (a.first == b.first) return a.second > b.second;
                 return a.first > b.first;
             });

        return vec.front().second;
    }
};
