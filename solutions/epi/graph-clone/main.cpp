#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct GraphVertex {
    int label;
    vector<GraphVertex*> edges;
};

GraphVertex* CloneGraph(GraphVertex* graph) {
    if (graph == nullptr) return nullptr;
    auto u = new GraphVertex{graph->label};

    vector<tuple<GraphVertex*, GraphVertex*>> st = {{graph, u}};
    unordered_map<GraphVertex*, GraphVertex*> seen;
    seen[graph] = u;

    while (!empty(st)) {
        auto [from, to] = st.back();
        st.pop_back();

        for (auto u : from->edges) {
            if (auto v = seen[u]; v != nullptr) {
                to->edges.push_back(v);
                continue;
            }

            auto v = new GraphVertex{u->label};
            seen[u] = v;
            to->edges.push_back(v);
            st.push_back({u, v});
        }
    }

    return u;
}

vector<int> CopyLabels(const vector<GraphVertex*>& edges) {
    vector<int> labels;
    transform(begin(edges), end(edges), back_inserter(labels),
              [](const auto& e) { return e->label; });
    return labels;
}

void CheckGraph(GraphVertex* node, const vector<GraphVertex>& graph) {
    if (!node || node == &graph[0]) {
        throw TestFailure("Graph was not copied");
    }

    unordered_set<GraphVertex*> vertex_set;
    queue<GraphVertex*> q;
    q.emplace(node);
    vertex_set.emplace(node);
    while (!q.empty()) {
        auto vertex = q.front();
        q.pop();
        if (vertex->label >= graph.size()) {
            throw TestFailure("Invalid vertex label");
        }
        vector<int> label1 = CopyLabels(vertex->edges),
                    label2 = CopyLabels(graph[vertex->label].edges);
        sort(begin(label1), end(label1));
        sort(begin(label2), end(label2));
        if (label1 != label2) {
            throw TestFailure("Edges mismatch");
        }
        for (GraphVertex* e : vertex->edges) {
            if (vertex_set.emplace(e).second) {
                q.emplace(e);
            }
        }
    }
    for (auto& v : vertex_set) {
        delete v;
    }
}

struct Edge {
    int from;
    int to;
};

namespace test_framework {
template <>
struct SerializationTrait<Edge> : UserSerTrait<Edge, int, int> {};
}  // namespace test_framework

void CloneGraphTest(int k, const vector<Edge>& edges) {
    vector<GraphVertex> graph;
    if (k <= 0) {
        throw runtime_error("Invalid k value");
    }
    graph.reserve(k);

    for (int i = 0; i < k; i++) {
        graph.push_back(GraphVertex{i});
    }

    for (const Edge& e : edges) {
        if (e.from < 0 || e.from >= k || e.to < 0 || e.to >= k) {
            throw runtime_error("Invalid vertex index");
        }
        graph[e.from].edges.push_back(&graph[e.to]);
    }
    GraphVertex* result = CloneGraph(&graph[0]);
    CheckGraph(result, graph);
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"k", "edges"};
    return GenericTestMain(args, "data.tsv", &CloneGraphTest,
                           DefaultComparator{}, param_names);
}
