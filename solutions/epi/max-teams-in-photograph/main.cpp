#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/timed_executor.h>

#include <stdexcept>
#include <unordered_map>
#include <vector>
using namespace std;

struct GraphVertex {
    vector<GraphVertex*> edges;
    // Set max_distance = 0 to indicate unvisited vertex.
    int max_distance = 0;
};

int FindLargestNumberTeams(vector<GraphVertex>* graph) {
    unordered_map<GraphVertex*, int> cache;

    function<int(GraphVertex*)> dfs = [&](GraphVertex* u) -> int {
        if (cache[u]) return cache[u];

        int distance = 1;
        for (int i = 0; i < size(u->edges); ++i) {
            auto v = u->edges[i];
            distance = max(distance, 1 + dfs(v));
        }

        return cache[u] = distance;
    };

    int result = 0;
    for (auto& pu : *graph) {
        result = max(result, dfs(&pu));
    }

    return result;
}

struct Edge {
    int from;
    int to;
};

namespace test_framework {
template <>
struct SerializationTrait<Edge> : UserSerTrait<Edge, int, int> {};
}  // namespace test_framework

int FindLargestNumberTeamsWrapper(TimedExecutor& executor, int k,
                                  const vector<Edge>& edges) {
    if (k <= 0) {
        throw runtime_error("Invalid k value");
    }

    vector<GraphVertex> graph(k, GraphVertex{});

    for (const Edge& e : edges) {
        if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k) {
            throw runtime_error("Invalid vertex index");
        }
        graph[e.from].edges.push_back(&graph[e.to]);
    }

    return executor.Run([&] { return FindLargestNumberTeams(&graph); });
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "k", "edges"};
    return GenericTestMain(args, "data.tsv", &FindLargestNumberTeamsWrapper,
                           DefaultComparator{}, param_names);
}
