class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto result = points;
        sort(result.begin(), result.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
             });
        return {result.begin(), result.begin() + k};
    }
};

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k == points.size()) return points;

        auto result = points;
        auto partition = [&result](int l, int r, int pivot_index) -> int {
            auto pivot_point = result[pivot_index];
            int pivot_value = pivot_point[0] * pivot_point[0] +
                              pivot_point[1] * pivot_point[1];

            swap(result[pivot_index], result[r]);

            int p = l, pl = l, pr = r - 1;
            while (pl <= pr) {
                int dist =
                    result[p][0] * result[p][0] + result[p][1] * result[p][1];
                if (dist < pivot_value) {
                    swap(result[p++], result[pl++]);
                } else {  // dist >= pivot_value
                    swap(result[p], result[pr--]);
                }
            }

            swap(result[pl], result[r]);

            return pl;
        };

        random_device rd;
        default_random_engine gen(rd());
        int l = 0, r = points.size() - 1;
        while (l < r) {
            int pivot_index = uniform_int_distribution<int>(l, r)(gen);
            pivot_index = partition(l, r, pivot_index);

            if (pivot_index == k) break;
            if (pivot_index < k) {
                l = pivot_index + 1;
            } else {  // pivot_index > k
                r = pivot_index - 1;
            }
        }

        return {result.begin(), result.begin() + k};
    }
};
