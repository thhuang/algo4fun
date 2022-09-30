class Solution {
    enum Side { Left, Right };

    struct Entry {
        int x, y;
        Side side;
    };

   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> height;
        height.insert(0);

        auto comp = [&](const Entry& a, const Entry& b) -> bool {
            return a.x > b.x;
        };

        priority_queue<Entry, vector<Entry>, decltype(comp)> pq(comp);
        for (const auto& b : buildings) {
            pq.push({b[0], b[2], Side::Left});
            pq.push({b[1], b[2], Side::Right});
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            Entry entry;
            while (true) {
                entry = pq.top();
                pq.pop();

                if (entry.side == Side::Left) {
                    height.insert(entry.y);
                } else {  // entry.side == Side::Right
                    height.erase(height.find(entry.y));
                }
                if (pq.empty() || pq.top().x != entry.x) break;
            }

            int y = *height.rbegin();
            if (!result.empty() && result.back()[1] == y) continue;
            result.push_back({entry.x, y});
        }

        return result;
    }
};

class Solution {
    struct Edge {
        bool isLeft;
        int x, h;
    };

   public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Edge> edges;
        for (const vector<int>& building : buildings) {
            edges.push_back({true, building[0], building[2]});
            edges.push_back({false, building[1], building[2]});
        }

        sort(edges.begin(), edges.end(),
             [](const Edge& a, const Edge& b) -> bool { return a.x < b.x; });

        vector<vector<int>> result;
        multiset<int> heights;
        heights.insert(0);
        for (int i = 0; i < edges.size(); ++i) {
            while (true) {
                if (edges[i].isLeft) {
                    heights.insert(edges[i].h);
                } else {
                    heights.erase(heights.find(edges[i].h));
                }
                if (i == edges.size() - 1 || edges[i].x != edges[i + 1].x) break;
                ++i;
            }

            int h = *heights.rbegin();
            if (!result.empty() && result.back()[1] == h) continue;
            result.push_back({edges[i].x, h});
        }

        return result;
    }
};
