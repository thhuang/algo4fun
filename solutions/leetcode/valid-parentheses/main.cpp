class Solution {
   public:
    bool isValid(string s) {
        unordered_map<char, char> pairs;
        pairs[')'] = '(', pairs[']'] = '[', pairs['}'] = '{';

        vector<char> vec;
        for (char c : s) {
            if (!pairs.count(c)) {
                vec.push_back(c);
                continue;
            }

            if (empty(vec) || vec.back() != pairs[c]) return false;
            vec.pop_back();
        }

        return empty(vec);
    }
};
