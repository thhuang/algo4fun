class Solution {
   public:
    int findTheWinner(int n, int k) {
        deque<int> friends(n);
        iota(friends.begin(), friends.end(), 1);

        auto next = [&](int i) -> int {
            return (i + k - 1 + friends.size()) % friends.size();
        };

        int p = 0;
        while (friends.size() > 1) {
            auto it = friends.erase(friends.begin() + next(p));
            p = it - friends.begin();
        }

        return friends[0];
    }
};
