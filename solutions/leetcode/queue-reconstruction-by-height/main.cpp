class Solution {
   public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 if (a[1] != b[1]) return a[1] < b[1];
                 return a[0] < b[0];
             });

        list<vector<int>> q;
        for (const vector<int>& p : people) {
            auto it = q.begin();
            int k = 0;
            while (true) {
                if (it == q.end()) {
                    q.push_back(p);
                    break;
                }
                if (it->at(0) >= p[0]) ++k;
                if (k > p[1]) {
                    q.insert(it, p);
                    break;
                }
                ++it;
            }
        }

        return {q.begin(), q.end()};
    }
};
