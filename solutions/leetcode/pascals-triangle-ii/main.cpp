class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> new_row(i + 1, 0);
            for (int j = 0; j < i + 1; ++j) {
                if (j > 0) new_row[j] += row[j - 1];
                if (j < i) new_row[j] += row[j];
            }
            row = new_row;
        }
        return row;
    }
};

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr, prev = {1};
        for (int i = 1; i <= rowIndex; ++i) {
            curr.assign(i + 1, 0);
            for (int j = 0; j < i + 1; ++j) {
                if (j > 0) curr[j] += prev[j - 1];
                if (j < i) curr[j] += prev[j];
            }
            prev = move(curr);
        }
        return prev;
    }
};

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        for (int i = 1, j = rowIndex, v = 1; i <= rowIndex; ++i, --j) {
            result.push_back(v = (long long)v * j / i);
        }
        return result;
    }
};

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        for (int i = 1, j = rowIndex; i <= rowIndex; ++i, --j) {
            result.push_back((long long)result.back() * j / i);
        }
        return result;
    }
};
