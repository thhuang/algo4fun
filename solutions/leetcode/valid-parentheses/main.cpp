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

class Solution {
    bool check(char open, char close) {
        return open == '(' && close == ')' || open == '[' && close == ']' ||
               open == '{' && close == '}';
    }

    bool isOpen(char c) { return c == '(' || c == '[' || c == '{'; }

   public:
    bool isValid(string s) {
        vector<int> op;
        for (char c : s) {
            if (isOpen(c)) {
                op.push_back(c);
            } else {  // is close
                if (op.empty()) return false;
                if (!check(op.back(), c)) return false;
                op.pop_back();
            }
        }
        return op.empty();
    }
};
