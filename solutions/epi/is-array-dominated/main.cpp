#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <algorithm>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

class Team {
   public:
    explicit Team(const vector<int>& height) {
        transform(begin(height), end(height), back_inserter(players_),
                  [](int h) { return Player{h}; });
    }
    // Checks if team0 can be placed in front of team1.
    static bool ValidPlacementExists(const Team& team0, const Team& team1) {
        priority_queue<Player> q0(begin(team0.players_), end(team0.players_));
        priority_queue<Player> q1(begin(team1.players_), end(team1.players_));

        while (!empty(q0) && !empty(q1)) {
            if (!(q0.top() < q1.top())) return false;
            q0.pop(), q1.pop();
        }

        return true;
    }

   private:
    struct Player {
        bool operator<(const Player& that) const {
            return height < that.height;
        }

        int height;
    };
    vector<Player> players_;
};

void ValidPlacementExistsWrapper(TimedExecutor& executor,
                                 const vector<int>& team0,
                                 const vector<int>& team1, bool expected_01,
                                 bool expected_10) {
    Team t0(team0), t1(team1);

    bool result_01 =
        executor.Run([&] { return Team::ValidPlacementExists(t0, t1); });
    bool result_10 =
        executor.Run([&] { return Team::ValidPlacementExists(t1, t0); });
    if (result_01 != expected_01 || result_10 != expected_10) {
        throw TestFailure("");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "team0", "team1", "expected_01",
                               "expected_10"};
    return GenericTestMain(args, "data.tsv", &ValidPlacementExistsWrapper,
                           DefaultComparator{}, param_names);
}
