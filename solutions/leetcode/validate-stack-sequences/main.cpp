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
