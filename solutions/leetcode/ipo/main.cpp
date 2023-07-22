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

class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();

        vector<array<int, 2>> projects(n);
        for (int i = 0; i < n; ++i) projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());

        int result = w;
        priority_queue<int> pq;
        for (int i = 0, j = 0; i < k; ++i) {
            while (j < n && projects[j][0] <= result) pq.push(projects[j++][1]);
            if (pq.empty()) break;
            result += pq.top();
            pq.pop();
        }

        return result;
    }
};
