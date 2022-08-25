class Leaderboard {
    unordered_map<int, multiset<int>::iterator> player2score;
    multiset<int> scores;

   public:
    void addScore(int playerId, int score) {
        int v = score;
        if (auto it = player2score.find(playerId); it != player2score.end()) {
            v += *it->second;
            scores.erase(it->second);
        }
        auto it = scores.insert(v);
        player2score[playerId] = it;
    }

    int top(int K) {
        int s = 0;
        for (auto it = scores.rbegin(); K; --K) s += *it++;
        return s;
    }

    void reset(int playerId) {
        auto it = player2score.find(playerId);
        scores.erase(it->second);
        player2score.erase(it);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
