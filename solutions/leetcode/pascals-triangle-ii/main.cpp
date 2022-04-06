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
