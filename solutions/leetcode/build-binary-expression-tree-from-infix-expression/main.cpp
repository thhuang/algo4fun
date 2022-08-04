/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right)
 * {}
 * };
 */
class Solution {
   public:
    Node* expTree(string s) {
        function<Node*(int&)> process = [&](int& i) -> Node* {
            vector<Node*> nodes;

            for (; i < s.size() && s[i] != ')'; ++i) {
                if (s[i] == '(') {
                    nodes.push_back(process(++i));
                } else {
                    nodes.push_back(new Node(s[i]));
                }
            }

            vector<Node*> new_nodes;
            for (int i = 0; i < nodes.size(); ++i) {
                if ((nodes[i]->val == '*' || nodes[i]->val == '/') &&
                    !nodes[i]->left) {
                    nodes[i]->left = new_nodes.back();
                    nodes[i]->right = nodes[i + 1];
                    new_nodes.back() = nodes[i];
                    ++i;
                } else {
                    new_nodes.push_back(nodes[i]);
                }
            }

            Node* result = new_nodes.front();
            for (int i = 1; i < new_nodes.size(); i += 2) {
                new_nodes[i]->left = result;
                new_nodes[i]->right = new_nodes[i + 1];
                result = new_nodes[i];
            }

            return result;
        };

        int i = 0;
        return process(i);
    }
};
