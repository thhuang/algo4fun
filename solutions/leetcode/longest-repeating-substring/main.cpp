class Solution {
    struct Node {
        array<Node*, 26> children = array<Node*, 26>();
        bool is_end = false;
    };

    Node* root = new Node;

   public:
    int longestRepeatingSubstring(string s) {
        unordered_set<string> substrings;

        int result = 0;
        for (int l = 0; l < s.size(); ++l) {
            auto p = root;
            for (int r = l; r < s.size(); ++r) {
                int i = s[r] - 'a';

                Node* q = p->children[i];
                if (q == nullptr) {
                    q = p->children[i] = new Node;
                } else if (q->is_end) {
                    result = max(result, r - l + 1);
                }
                q->is_end = true;
                p = q;
            }
        }

        return result;
    }
};
