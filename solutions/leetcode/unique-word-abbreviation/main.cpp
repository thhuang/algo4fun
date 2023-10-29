class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> mp;

    string toAbbr(string w) {
        if (w.size() == 2) return w;
        return w.front() + to_string(w.size() - 2) + w.back();
    }

   public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const string& w : dictionary) {
            mp[toAbbr(w)].insert(w);
        }
    }

    bool isUnique(string word) {
        string abbr = toAbbr(word);
        const unordered_set<string>& st = mp[abbr];
        if (st.empty()) return true;
        if (st.size() > 1) return false;
        if (st.count(word) == 1) return true;
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
