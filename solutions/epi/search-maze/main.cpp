#include <epi/generic_test.h>
#include <epi/serialization_traits.h>
#include <epi/test_failure.h>
#include <epi/timed_executor.h>

#include <array>
#include <istream>
#include <string>
#include <vector>
using namespace std;

const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

enum class Color { kWhite, kBlack };
struct Coordinate {
    bool operator==(const Coordinate& that) const {
        return x == that.x && y == that.y;
    }

    int x, y;
};

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s,
                              const Coordinate& e) {
    vector<Coordinate> path;

    int n = maze.size();
    int m = maze[0].size();

    function<bool(Coordinate)> search = [&](Coordinate c) -> bool {
        if (c.x < 0 || c.x >= n || c.y < 0 || c.y >= m) return false;
        if (maze[c.x][c.y] == Color::kBlack) return false;
        if (c == e) {
            path.push_back({c.x, c.y});
            return true;
        }

        maze[c.x][c.y] = Color::kBlack;
        for (auto dir : directions) {
            if (!search(Coordinate{c.x + dir[0], c.y + dir[1]})) continue;
            path.push_back({c.x, c.y});
            return true;
        }

        return false;
    };

    search(s);
    reverse(path.begin(), path.end());

    return path;
}

namespace test_framework {
template <>
struct SerializationTrait<Color> : SerializationTrait<int> {
    using serialization_type = Color;

    static serialization_type Parse(const json& json_object) {
        return static_cast<serialization_type>(
            SerializationTrait<int>::Parse(json_object));
    }
};
}  // namespace test_framework

namespace test_framework {
template <>
struct SerializationTrait<Coordinate> : UserSerTrait<Coordinate, int, int> {
    static vector<string> GetMetricNames(const string& arg_name) { return {}; }

    static vector<int> GetMetrics(const Coordinate& x) { return {}; }
};
}  // namespace test_framework

bool PathElementIsFeasible(const vector<vector<Color>>& maze,
                           const Coordinate& prev, const Coordinate& cur) {
    if (!(0 <= cur.x && cur.x < maze.size() && 0 <= cur.y &&
          cur.y < maze[cur.x].size() && maze[cur.x][cur.y] == Color::kWhite)) {
        return false;
    }
    return cur == Coordinate{prev.x + 1, prev.y} ||
           cur == Coordinate{prev.x - 1, prev.y} ||
           cur == Coordinate{prev.x, prev.y + 1} ||
           cur == Coordinate{prev.x, prev.y - 1};
}

bool SearchMazeWrapper(TimedExecutor& executor,
                       const vector<vector<Color>>& maze, const Coordinate& s,
                       const Coordinate& e) {
    vector<vector<Color>> copy = maze;

    auto path = executor.Run([&] { return SearchMaze(copy, s, e); });

    if (path.empty()) {
        return s == e;
    }

    if (!(path.front() == s) || !(path.back() == e)) {
        throw TestFailure("Path doesn't lay between start and end points");
    }

    for (size_t i = 1; i < path.size(); i++) {
        if (!PathElementIsFeasible(maze, path[i - 1], path[i])) {
            throw TestFailure("Path contains invalid segments");
        }
    }

    return true;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "maze", "s", "e"};
    return GenericTestMain(args, "data.tsv", &SearchMazeWrapper,
                           DefaultComparator{}, param_names);
}
