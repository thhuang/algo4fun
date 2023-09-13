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

class Solution {
   public:
    string rearrangeString(string s, int k) {
        array<int, 26> charFreq;
        charFreq.fill(0);
        for (char c : s) ++charFreq[c - 'a'];

        priority_queue<array<int, 2>> pq;
        for (int i = 0; i < 26; ++i) {
            if (int f = charFreq[i]; f > 0) {
                pq.push({f, i});
            }
        }

        string result;
        queue<array<int, 3>> q;

        for (int i = 0; i < s.size(); ++i) {
            while (!q.empty() && i - k >= q.front()[0]) {
                auto [_, f, c] = q.front();
                q.pop();
                pq.push({f, c});
            }

            if (pq.empty()) return "";

            auto [f, c] = pq.top();
            pq.pop();

            result += ('a' + c);

            if (--f > 0) q.push({i, f, c});
        }

        return result;
    }
};
