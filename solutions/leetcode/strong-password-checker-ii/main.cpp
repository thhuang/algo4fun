class Solution {
   public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;

        bool has_lower = false;
        for (char c : password) {
            if (islower(c)) {
                has_lower = true;
                break;
            }
        }
        if (!has_lower) return false;

        bool has_upper = false;
        for (char c : password) {
            if (isupper(c)) {
                has_upper = true;
                break;
            }
        }
        if (!has_upper) return false;

        bool has_digit = false;
        for (char c : password) {
            if (isdigit(c)) {
                has_digit = true;
                break;
            }
        }
        if (!has_digit) return false;

        bool has_special = false;
        string special = "!@#$%^&*()-+";
        unordered_set<char> special_chars;
        for (char c : special) special_chars.insert(c);
        for (char c : password) {
            if (special_chars.count(c)) {
                has_special = true;
                break;
            }
        }
        if (!has_special) return false;

        for (int i = 1; i < password.size(); ++i) {
            if (password[i] == password[i - 1]) return false;
        }

        return true;
    }
};
