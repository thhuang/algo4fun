class Solution {
   public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        unordered_map<string, string> log2key;
        unordered_map<string, string> log2id;

        for (int i = 0; i < logs.size(); ++i) {
            const string& s = logs[i];

            stringstream ss;
            if (isdigit(s.back())) {
                ss << "1" << setw(3) << setfill('0') << i;
            } else {  // isdigit(s.back()) == false
                int l = find(s.begin(), s.end(), ' ') - s.begin() + 1;
                ss << "0" << s.substr(l);
                log2id[s] = s.substr(0, l);
            }

            log2key[s] = ss.str();
        }

        sort(logs.begin(), logs.end(),
             [&](const string& a, const string& b) -> bool {
                 if (log2key[a] != log2key[b]) return log2key[a] < log2key[b];
                 return log2id[a] < log2id[b];
             });

        return logs;
    }
};
