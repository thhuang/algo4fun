class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        auto it = pushed.begin();
        for (int v : popped) {
            while (s.empty() || s.top() != v) {
                if (it == pushed.end()) return false;
                s.push(*it++);
            }
            s.pop();
        }
        return true;
    }
};

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int m = pushed.size(), n = popped.size();
        int i = 0, j = 0;

        stack<int> stk;
        while (i < m || j < n) {
            if (stk.empty() || stk.top() != popped[j]) {
                if (i == m) return false;
                stk.push(pushed[i++]);
            } else {
                ++j;
                stk.pop();
            }
        }
        return true;
    }
};
