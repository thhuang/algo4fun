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
