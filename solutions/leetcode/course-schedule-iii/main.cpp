class Solution {
   public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool {
                 return a[1] < b[1];
             });

        priority_queue<int> pq;
        int t = 0;
        int count = 0;
        for (const auto& c : courses) {
            if (t + c[0] <= c[1]) {
                ++count;
                t += c[0];
                pq.push(c[0]);
                continue;
            }

            if (!pq.empty() && pq.top() > c[0]) {
                t -= pq.top() - c[0];
                pq.pop();
                pq.push(c[0]);
            }
        }

        return count;
    }
};
