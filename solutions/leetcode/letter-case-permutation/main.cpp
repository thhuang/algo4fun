class Solution {
   public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> result;

        string perm;
        function<void(int)> search = [&](int i) -> void {
            if (i == n) {
                result.push_back(perm);
                return;
            }

            if (!isalpha(s[i])) {
                perm.push_back(s[i]);
                search(i + 1);
                perm.pop_back();
                return;
            }

            perm.push_back(tolower(s[i]));
            search(i + 1);
            perm.pop_back();

            perm.push_back(toupper(s[i]));
            search(i + 1);
            perm.pop_back();
        };

        search(0);

        return result;
    }
};
