/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<Node*>> nodes(n, vector<Node*>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nodes[i][j] = new Node(grid[i][j], true);
            }
        }

        while (nodes.size() > 1) {
            int m = nodes.size() / 2;
            vector<vector<Node*>> newNodes(m, vector<Node*>(m));

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    int x = i * 2;
                    int y = j * 2;
                    vector<Node*> children;

                    bool shouldMerge = true;
                    for (int dx = 0; dx < 2; ++dx) {
                        for (int dy = 0; dy < 2; ++dy) {
                            auto node = nodes[x + dx][y + dy];
                            if (!node->isLeaf) shouldMerge = false;
                            children.push_back(node);
                        }
                    }

                    if (shouldMerge) {
                        for (int k = 1; k < 4; ++k) {
                            if (children[k]->val != children[0]->val) {
                                shouldMerge = false;
                                break;
                            }
                        }
                    }

                    if (shouldMerge) {
                        newNodes[i][j] = new Node(children[0]->val, true);
                        for (auto node : children) delete node;
                    } else {
                        newNodes[i][j] = new Node(0, false, children[0], children[1], children[2], children[3]);
                    }
                }
            }

            nodes = move(newNodes);
        }

        return nodes[0][0];
    }
};

class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int, int, int)> dfs = [&](int r, int c, int n) -> Node* {
            if (n == 1) return new Node(grid[r][c], true);

            int m = n / 2;
            array<Node*, 4> children = {
                dfs(r, c, m),
                dfs(r, c + m, m),
                dfs(r + m, c, m),
                dfs(r + m, c + m, m)
            };

            int sum = 0;
            bool fourLeaves = true;
            for (auto u : children) {
                sum += u->val;
                fourLeaves &= u->isLeaf;
            }

            if (fourLeaves && (sum == 0 || sum == 4)) {
                for (auto &u : children) delete u;
                return new Node(sum == 4, true);
            }

            return new Node(true, false, children[0], children[1], children[2], children[3]);
        };
        
        return dfs(0, 0, grid.size());
    }
};
