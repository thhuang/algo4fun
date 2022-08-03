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

class Solution {
   public:
    int minSwaps(vector<int>& data) {
        int total = 0;
        for (int v : data) total += v;
        if (total <= 1) return 0;

        int window = 0;
        for (int i = 0; i < total - 1; ++i) window += data[i];

        int result = data.size();
        for (int i = total - 1; i < data.size(); ++i) {
            window += data[i];
            result = min(result, total - window);
            window -= data[i - total + 1];
        }

        return result;
    }
};
