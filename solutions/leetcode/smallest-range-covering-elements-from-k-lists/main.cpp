class Solution {
    typedef vector<int>::iterator vit;

   public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mx = numeric_limits<int>::min();
        priority_queue<tuple<int, vit, vit>, vector<tuple<int, vit, vit>>, greater<>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i].front());
            pq.push({nums[i].front(), nums[i].begin(), nums[i].end()});
        }

        vector<int> result = {get<0>(pq.top()), mx};
        while (true) {
            auto [mn, it, it_end] = pq.top();
            pq.pop();

            if (result[1] - result[0] > mx - mn) result = {mn, mx};

            if (++it == it_end) break;

            mx = max(mx, *it);
            pq.push({*it, it, it_end});
        }

        return result;
    }
};
