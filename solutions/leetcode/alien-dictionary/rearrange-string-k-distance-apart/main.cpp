class Solution {
   public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> char_count;
        for (char c : s) ++char_count[c];

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for (auto [c, cnt] : char_count) pq.push({cnt, c});

        string result;
        deque<pair<int, char>> q;
        while (!pq.empty()) {
            auto [cnt, c] = pq.top();
            pq.pop();

            result.push_back(c);
            q.push_back({cnt - 1, c});

            if (q.size() >= k) {
                if (q.front().first > 0) pq.push(q.front());
                q.pop_front();
            }
        }

        return result.size() == s.size() ? result : "";
    }
};
