class Solution {
   public:
    int minSwaps(vector<int>& data) {
        int total = 0;
        for (int v : data) total += v;

        int max_in_window = 0;
        for (int i = 0, ones = 0; i < data.size(); ++i) {
            if (i >= total) ones -= data[i - total];

            ones += data[i];
            max_in_window = max(max_in_window, ones);
        }

        return total - max_in_window;
    }
};
