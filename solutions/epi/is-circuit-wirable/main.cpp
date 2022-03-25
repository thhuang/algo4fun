#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/timed_executor.h>

#include <stdexcept>
#include <unordered_map>
#include <vector>
using namespace std;

struct GraphVertex {
    int d = -1;
    vector<GraphVertex*> edges;
};

bool IsAnyPlacementFeasible(vector<GraphVertex>* graph) {
    unordered_map<GraphVertex*, bool> seen;

    function<bool(GraphVertex*, bool)> search = [&](GraphVertex* u,
                                                    bool group_a) -> bool {
        if (auto it = seen.find(u); it != seen.end()) {
            return it->second == group_a;
        }

        seen[u] = group_a;
        for (int i = 0; i < size(u->edges); ++i) {
            if (!search(u->edges[i], !group_a)) return false;
        }
        return true;
    };

    for (int i = 0; i < size(*graph); ++i) {
        auto u = &graph->at(i);
        if (seen.count(u)) continue;
        if (!search(u, true)) return false;
    }

    return true;
}

struct Edge {
    int from;
    int to;
};

namespace test_framework {
template <>
struct SerializationTrait<Edge> : UserSerTrait<Edge, int, int> {};
}  // namespace test_framework

bool IsAnyPlacementFeasibleWrapper(TimedExecutor& executor, int k,
                                   const vector<Edge>& edges) {
    vector<GraphVertex> graph;
    if (k <= 0) {
        throw runtime_error("Invalid k value");
    }
    graph.reserve(k);

    for (int i = 0; i < k; i++) {
        graph.push_back(GraphVertex{});
    }

    for (auto& e : edges) {
        if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k) {
            throw runtime_error("Invalid vertex index");
        }
        graph[e.from].edges.push_back(&graph[e.to]);
    }

    return executor.Run([&] { return IsAnyPlacementFeasible(&graph); });
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "k", "edges"};
    return GenericTestMain(args, "data.tsv", &IsAnyPlacementFeasibleWrapper,
                           DefaultComparator{}, param_names);
}
