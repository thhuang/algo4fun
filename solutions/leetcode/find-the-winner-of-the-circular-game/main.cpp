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

// Josephus problem
class Solution {
    int solve(int n, int k) {
        if (n == 1) return 0;
        return (solve(n - 1, k) + k) % n;
    };

   public:
    int findTheWinner(int n, int k) { return solve(n, k) + 1; }
};
