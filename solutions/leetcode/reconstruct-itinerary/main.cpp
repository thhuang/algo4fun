class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, int> ticketCount;
        unordered_map<string, set<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
            ++ticketCount[ticket[0] + ticket[1]];
        }

        vector<string> result = {"JFK"};

        function<bool()> dfs = [&]() -> bool {
            if (result.size() == tickets.size() + 1) return true;

            string u = result.back();

            for (auto v : adj[u]) {
                string ticket = u + v;
                if (ticketCount[ticket] == 0) continue;

                --ticketCount[ticket];
                result.push_back(v);
                if (dfs()) return true;
                result.pop_back();
                ++ticketCount[ticket];
            }

            return false;
        };

        dfs();

        return result;
    }
};
