class Solution {
   public:
    string reorganizeString(string s) {
        array<int, 26> counts;
        fill(counts.begin(), counts.end(), 0);

        for (char c : s) ++counts[c - 'a'];

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (counts[i]) pq.push({counts[i], 'a' + i});
        }

        deque<pair<int, char>> buf;

        string result;
        while (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();

            if (!result.empty() && result.back() == ch) return "";
            result += ch;

            while (!buf.empty()) {
                pq.push(buf.front());
                buf.pop_front();
            }

            if (cnt > 1) buf.push_back({cnt - 1, ch});
        }

        if (!buf.empty()) return "";
        return result;
    }
};
