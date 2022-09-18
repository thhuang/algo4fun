class Solution {
    struct Node {
        array<Node*, 26> children = array<Node*, 26>();
        int score = 0;
    };

    void insert(const string& s) {
        auto p = root;
        for (char c : s) {
            int i = c - 'a';
            if (p->children[i] == nullptr) p->children[i] = new Node;
            p = p->children[i];
            ++p->score;
        }
    }

    int score(const string& s) {
        int result = 0;
        auto p = root;
        for (char c : s) {
            int i = c - 'a';
            p = p->children[i];
            result += p->score;
        }
        return result;
    }

    Node* root = new Node;

   public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for (const string& w : words) insert(w);
        vector<int> result;
        for (const string& w : words) result.push_back(score(w));
        return result;
    }
};
