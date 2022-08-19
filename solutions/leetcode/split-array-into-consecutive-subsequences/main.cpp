class Solution {
   public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> mp;  // {val, {len}}
        for (int v : nums) {
            auto it = mp.find(v - 1);
            if (it == mp.end()) {
                mp[v].push(1);
            } else {
                mp[v].push(it->second.top() + 1);
                it->second.pop();
                if (it->second.empty()) mp.erase(it);
            }
        }

        for (auto& [v, pq] : mp) {
            while (!pq.empty()) {
                if (pq.top() < 3) return false;
                pq.pop();
            }
        }

        return true;
    }
};

class Solution {
    struct Entry {
        int val, one, two, three;
    };

   public:
    bool isPossible(vector<int>& nums) {
        vector<Entry> dp = {{nums.front() - 2, 0, 0, 0},
                            {nums.front() - 1, 0, 0, 0}};

        function<void()> update = [&]() -> void {
            if (dp[0].one) {
                --dp[0].one;
                ++dp[1].two;
            } else if (dp[0].two) {
                --dp[0].two;
                ++dp[1].three;
            } else if (dp[0].three) {
                --dp[0].three;
                ++dp[1].three;
            } else {
                ++dp[1].one;
            }
        };

        for (int v : nums) {
            int p = v - 1;
            if (dp[0].val != p && dp[1].val != p) {
                if (dp[0].one || dp[0].two || dp[1].one || dp[1].two)
                    return false;
                dp = {{p, 0, 0, 0}, {v, 1, 0, 0}};
            } else if (dp[0].val == p) {
                update();
            } else {  // dp[1].val == p
                if (dp[0].one || dp[0].two) return false;
                dp = {dp[1], {v, 0, 0, 0}};
                update();
            }
        }

        return dp[0].one == 0 && dp[0].two == 0 && dp[1].one == 0 &&
               dp[1].two == 0;
    }
};
