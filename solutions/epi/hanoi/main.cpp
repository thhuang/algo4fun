#include <epi/generic_test.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <array>
#include <stack>
#include <string>
#include <vector>
using namespace std;

const int kNumPegs = 3;

void MoveRing(int rings_to_move, int from, int to, int use,
              vector<vector<int>>& result) {
    if (!rings_to_move) return;
    MoveRing(rings_to_move - 1, from, use, to, result);
    result.push_back({from, to});
    MoveRing(rings_to_move - 1, use, to, from, result);
}

vector<vector<int>> ComputeTowerHanoi(int num_rings) {
    vector<vector<int>> result;
    MoveRing(num_rings, 0, 1, 2, result);
    return result;
}

void ComputeTowerHanoiWrapper(TimedExecutor& executor, int num_rings) {
    array<stack<int>, kNumPegs> pegs;
    for (int i = num_rings; i >= 1; --i) {
        pegs[0].push(i);
    }

    vector<vector<int>> result =
        executor.Run([&] { return ComputeTowerHanoi(num_rings); });

    for (const vector<int>& operation : result) {
        int from_peg = operation[0], to_peg = operation[1];
        if (!pegs[to_peg].empty() &&
            pegs[from_peg].top() >= pegs[to_peg].top()) {
            throw TestFailure("Illegal move from " +
                              to_string(pegs[from_peg].top()) + " to " +
                              to_string(pegs[to_peg].top()));
        }
        pegs[to_peg].push(pegs[from_peg].top());
        pegs[from_peg].pop();
    }
    array<stack<int>, kNumPegs> expected_pegs1, expected_pegs2;
    for (int i = num_rings; i >= 1; --i) {
        expected_pegs1[1].push(i);
    }
    for (int i = num_rings; i >= 1; --i) {
        expected_pegs2[2].push(i);
    }
    if (pegs != expected_pegs1 && pegs != expected_pegs2) {
        throw TestFailure("Pegs doesn't place in the right configuration");
    }
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "num_rings"};
    return GenericTestMain(args, "data.tsv", &ComputeTowerHanoiWrapper,
                           DefaultComparator{}, param_names);
}
