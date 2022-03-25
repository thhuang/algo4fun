#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/timed_executor.h>

#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct GraphVertex {
    vector<GraphVertex*> edges;
};

bool IsDeadlocked(vector<GraphVertex>* graph) {
    unordered_map<GraphVertex*, vector<GraphVertex*>> edges;
    for (int i = 0; i < size(*graph); ++i) {
        auto u = &graph->at(i);
        edges[u] = u->edges;
    }

    unordered_map<GraphVertex*, int> seen;
    function<bool(GraphVertex*)> search = [&](GraphVertex* u) -> bool {
        if (seen[u] == 1) return true;
        if (seen[u] == 2) return false;
        seen[u] = 1;
        for (auto v : edges[u]) {
            if (search(v)) return true;
        }
        seen[u] = 2;
        return false;
    };

    for (int i = 0; i < size(*graph); ++i) {
        auto u = &graph->at(i);
        if (seen.count(u)) continue;
        if (search(u)) return true;
    }

    return false;
}

struct Edge {
    int from;
    int to;
};

namespace test_framework {
template <>
struct SerializationTrait<Edge> : UserSerTrait<Edge, int, int> {};
}  // namespace test_framework

bool HasCycleWrapper(TimedExecutor& executor, int num_nodes,
                     const vector<Edge>& edges) {
    vector<GraphVertex> graph;
    if (num_nodes <= 0) {
        throw runtime_error("Invalid num_nodes value");
    }
    graph.reserve(num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        graph.push_back(GraphVertex{});
    }

    for (const Edge& e : edges) {
        if (e.from < 0 || e.from >= num_nodes || e.to < 0 ||
            e.to >= num_nodes) {
            throw runtime_error("Invalid vertex index");
        }
        graph[e.from].edges.push_back(&graph[e.to]);
    }

    return executor.Run([&] { return IsDeadlocked(&graph); });
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "num_nodes", "edges"};
    return GenericTestMain(args, "data.tsv", &HasCycleWrapper,
                           DefaultComparator{}, param_names);
}
