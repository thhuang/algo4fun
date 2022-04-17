class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

        string curr = s.substr(0, 10);
        unordered_map<string, int> count;
        ++count[curr];

        for (int i = 10; i < s.size(); ++i) {
            curr = curr.substr(1) + s[i];
            ++count[curr];
        }

        vector<string> result;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > 1) result.push_back(it->first);
        }

        return result;
    }
};

class Solution {
    unordered_map<char, int> score = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    int base = 4;

   public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

        int curr = 0;
        int base9 = 1;
        for (int i = 0; i < 10; ++i) {
            if (i > 0) base9 *= base;
            curr = curr * base + score[s[i]];
        }

        unordered_map<int, int> count;
        ++count[curr];

        vector<string> result;
        for (int i = 10; i < s.size(); ++i) {
            curr -= score[s[i - 10]] * base9;
            curr = curr * base + score[s[i]];
            if (++count[curr] == 2) result.push_back(s.substr(i - 9, 10));
        }

        return result;
    }
};
