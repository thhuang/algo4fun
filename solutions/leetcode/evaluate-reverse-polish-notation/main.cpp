class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        vector<int> vals;
        for (const string& t : tokens) {
            if (isdigit(t.back())) {
                vals.push_back(stoi(t));
                continue;
            }

            int b = vals.back();
            vals.pop_back();
            int a = vals.back();
            vals.pop_back();

            switch (t[0]) {
                case '+':
                    vals.push_back(a + b);
                    break;
                case '-':
                    vals.push_back(a - b);
                    break;
                case '*':
                    vals.push_back(a * b);
                    break;
                case '/':
                    vals.push_back(a / b);
                    break;
            }
        }

        return vals.back();
    }
};
