class Solution {
    struct Node {
        int count = 0;
        array<Node*, 26> children = array<Node*, 26>();
    
        ~Node() {
            for (auto p : children) delete p;
        }
    };
    
    void insert(Node* root, const string& s) {
        auto p = root;
        for (char c : s) {
            int i = c - 'a';
            if (p->children[i] == nullptr) p->children[i] = new Node;
            p = p->children[i];
            ++p->count;
        }
    }
    
    int firstDiff(Node* root, const string& s) {
        auto p = root;
        for (int i = 0; i < s.size(); ++i) {
            p = p->children[s[i] - 'a'];
            if (p->count == 1) return i;
        }
        return s.size();
    }
    
   public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        unordered_map<string, string> mp;
        
        array<array<unordered_map<int, vector<string>>, 26>, 26> groups;
        for (const string& w : words) groups[w.front() - 'a'][w.back() - 'a'][w.size()].push_back(w);
        
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                const auto& length_words = groups[i][j];
                for (const auto& [length, ws] : length_words) {
                    if (length <= 3) {
                        for (const string& w : ws) mp[w] = w;
                        continue;
                    }
                    if (ws.size() == 1) {
                        const string& w = ws.front();
                        mp[w] = w.front() + to_string(w.size() - 2) + w.back();
                        continue;
                    }

                    auto forward = new Node;
                    for (const string& w : ws) insert(forward, w);
                    for (const string& w : ws) {
                        int l = firstDiff(forward, w);
                        int v = w.size() - l - 2;
                        if (v < 2) {
                            mp[w] = w;
                        } else {
                            mp[w] = w.substr(0, w.size() - v - 1) + to_string(v) + w.back();
                        }
                    }
                    delete forward;
                }
            }
        }
        
        vector<string> result;
        for (const string& w : words) result.push_back(mp[w]);
        return result;
    }
};
