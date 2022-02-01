#include <epi/fmt_print.h>
#include <epi/generic_test.h>
#include <epi/serialization_traits.h>

#include <algorithm>
#include <tuple>
using namespace std;

struct Rect {
    int x, y, width, height;
};

bool IsIntersect(const Rect& r1, const Rect& r2) {
    if (r1.x < r2.x && r1.x + r1.width < r2.x) return false;
    if (r1.x > r2.x && r2.x + r2.width < r1.x) return false;
    if (r1.y < r2.y && r1.y + r1.height < r2.y) return false;
    if (r1.y > r2.y && r2.y + r2.height < r1.y) return false;
    return true;
}

Rect IntersectRectangle(const Rect& r1, const Rect& r2) {
    if (!IsIntersect(r1, r2)) {
        return {0, 0, -1, -1};
    }

    int x1 = max(r1.x, r2.x);
    int x2 = min(r1.x + r1.width, r2.x + r2.width);
    int y1 = max(r1.y, r2.y);
    int y2 = min(r1.y + r1.height, r2.y + r2.height);

    return {x1, y1, x2 - x1, y2 - y1};
}

bool operator==(const Rect& r1, const Rect& r2) {
    return std::tie(r1.x, r1.y, r1.width, r1.height) ==
           std::tie(r2.x, r2.y, r2.width, r2.height);
}

template <>
struct SerializationTraits<Rect> : UserSerTraits<Rect, int, int, int, int> {
    static std::vector<std::string> GetMetricNames(
        const std::string& arg_name) {
        return {FmtStr("height({})", arg_name), FmtStr("width({})", arg_name)};
    }

    static std::vector<int> GetMetrics(const Rect& x) {
        return {x.height, x.width};
    }
};

std::ostream& operator<<(std::ostream& out, const Rect& r) {
    return PrintTo(out, std::make_tuple(r.x, r.y, r.width, r.height));
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"r1", "r2"};
    return GenericTestMain(args, "main.cpp", "data.tsv", &IntersectRectangle,
                           DefaultComparator{}, param_names);
}
