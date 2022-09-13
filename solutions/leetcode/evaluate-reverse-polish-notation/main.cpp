class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        vector<long> st;

        for (const string& t : tokens) {
            if (isdigit(t.back())) {
                st.push_back(stoi(t));
                continue;
            }

            int v = st.back();
            st.pop_back();

            switch (t[0]) {
                case '+':
                    st.back() += v;
                    break;
                case '-':
                    st.back() -= v;
                    break;
                case '*':
                    st.back() *= v;
                    break;
                case '/':
                    st.back() /= v;
                    break;
            }
        }

        return st.back();
    }
};
