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
    unordered_map<char, int> char2score = {
        {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    int base = char2score.size();

   public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 11) return {};

        unordered_map<int, int> score_count;

        int score = 0;
        int base9 = 1;
        for (int i = 0; i < 9; ++i) {
            score = score * base + char2score[s[i]];
            base9 *= base;
        }

        vector<string> result;
        for (int i = 9; i < s.size(); ++i) {
            score = score * base + char2score[s[i]];
            if (++score_count[score] == 2)
                result.push_back(s.substr(i - 9, 10));
            score -= base9 * char2score[s[i - 9]];
        }

        return result;
    }
};
