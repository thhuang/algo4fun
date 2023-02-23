class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects(n);
        for (int i = 0; i < profits.size(); ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end(), greater<>());

        int result = w;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            while (!projects.empty() && projects.back().first <= result) {
                pq.push(projects.back().second);
                projects.pop_back();
            }

            if (pq.empty()) break;

            result += pq.top();
            pq.pop();
        }

        return result;
    }
};
