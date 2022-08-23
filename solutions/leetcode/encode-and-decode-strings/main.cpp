class Codec {
    const int prefix = 3;

   public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        for (const string& s : strs) {
            ss << setw(prefix) << s.size() << s;
        }
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.size()) {
            int n = stoi(s.substr(i, prefix));
            i += prefix;
            strs.emplace_back(s.begin() + i, s.begin() + i + n);
            i += n;
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
