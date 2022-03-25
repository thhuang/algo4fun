#include <epi/generic_test.h>
#include <epi/timed_executor.h>

#include <deque>
#include <vector>
using namespace std;

const vector<tuple<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void FlipColor(int x, int y, vector<deque<bool>>* image_ptr) {
    auto& mat = *image_ptr;
    bool color = mat[x][y];
    int n = mat.size();
    int m = mat[0].size();

    vector<tuple<int, int>> st = {{x, y}};
    while (!empty(st)) {
        auto [i, j] = st.back();
        st.pop_back();

        if (i < 0 || i >= n || j < 0 || j >= m) continue;
        if (mat[i][j] != color) continue;

        mat[i][j] = !color;

        for (auto [di, dj] : directions) {
            st.push_back({i + di, j + dj});
        }
    }
}

vector<vector<int>> FlipColorWrapper(TimedExecutor& executor, int x, int y,
                                     vector<vector<int>> image) {
    vector<deque<bool>> b;
    b.reserve(image.size());
    for (const vector<int>& row : image) {
        deque<bool> tmp;
        tmp.resize(row.size());
        for (int i = 0; i < row.size(); ++i) {
            tmp[i] = static_cast<bool>(row[i]);
        }
        b.push_back(tmp);
    }

    executor.Run([&] { FlipColor(x, y, &b); });

    image.resize(b.size());

    for (int i = 0; i < image.size(); ++i) {
        image[i].resize(b.size());
        for (int j = 0; j < image[i].size(); ++j) {
            image[i][j] = b[i][j];
        }
    }
    return image;
}

int main(int argc, char* argv[]) {
    vector<string> args{argv + 1, argv + argc};
    vector<string> param_names{"executor", "x", "y", "image"};
    return GenericTestMain(args, "data.tsv", &FlipColorWrapper,
                           DefaultComparator{}, param_names);
}
