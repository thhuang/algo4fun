class Solution {
   public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> score(n, 0);
        for (int i = 0; i < n; ++i) {
            score[edges[i]] += i;
        }
        return max_element(score.begin(), score.end()) - score.begin();
    }
};
